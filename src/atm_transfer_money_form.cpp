#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QDesktopWidget>
#include "atm_transfer_money_form.h"
#include "atm_main_function_form.h"
#include "ui_atm_transfer_money_form.h"

QString card_id_;

ATMTransferMoneyForm::ATMTransferMoneyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMTransferMoneyForm)
{
    ui->setupUi(this);
    this->setWindowTitle("转账界面");
    this->setFixedSize(this->width(), this->height());
}

ATMTransferMoneyForm::~ATMTransferMoneyForm()
{
    delete ui;
}

void ATMTransferMoneyForm::on_button_accept_a_clicked()
{
    card_id_ = ui->line_edit_card_id->text();

    QString tables = " user_information ";
    QString properties = " user_name, card_id ";
    QString condition = " card_id = ";

    QSqlQuery query;
    query.exec("select * from user_information");

    int flag = 0;
    int index;

    while (query.next()) {
        QSqlRecord record = query.record();
        index = record.indexOf("card_id");
        if (query.value(index).toString() == card_id_) {
            flag = 1;
            break;
        }
    }

    if (!flag) {
        QMessageBox::warning(this, tr("错误"), tr("没有此银行卡账号！"), tr("是"));
        ui->line_edit_card_id->clear();
        ui->line_edit_card_money->clear();
        return ;
    }

    QSqlQueryModel *card_info_query_model = new QSqlQueryModel();
    card_info_query_model->setQuery("select" + properties + "from" + tables +
                                    "where"  + condition + card_id_);
    card_info_query_model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
    card_info_query_model->setHeaderData(1, Qt::Horizontal, tr("银行卡账号"));

    ui->table_view_card_info->setEditTriggers(
        QAbstractItemView::NoEditTriggers);
    ui->table_view_card_info->setModel(card_info_query_model);
    ui->table_view_card_info->show();
}

void ATMTransferMoneyForm::on_button_accept_b_clicked()
{
    QString card_money = ui->line_edit_card_money->text();

    if (card_money.toInt() == 0) {
        QMessageBox::warning(this, tr("警告"), tr("转账金额不能为空！"), tr("是"));
        return ;
    }

    QString table     = " card_information ";
    QString property  = " card_money ";
    QString condition = " card_id = " + card_id_;

    QSqlQuery query;
    query.exec("select" + property + "from" + table + "where" + condition);

    int index;
    int money;

    if (query.next()) {
        QSqlRecord record;
        record = query.record();
        index  = record.indexOf("card_money");
        money = query.value(index).toInt();
    }
    else {
        QMessageBox::warning(this, tr("错误"), tr("操作失败！"), tr("是"));
        return ;
    }

    QString money_all = QString::number((card_money.toInt() + money), 10);

    query.clear();
    query.exec("update" + table + "set" + property + "=" + money_all + " where"
               + condition);

    if (query.isActive()) {
        QMessageBox::information(this, tr("提示"), tr("转账成功！"), tr("是"));
        return ;
    }
    else {
        QMessageBox::warning(this, tr("错误"), tr("转账失败！"), tr("是"));
        return ;
    }
}

void ATMTransferMoneyForm::on_button_reset_clicked()
{
    ui->line_edit_card_id->clear();
    ui->line_edit_card_money->clear();
}

void ATMTransferMoneyForm::on_button_return_clicked()
{
    ATMMainFunctionForm *atm_main_function = new ATMMainFunctionForm();
    atm_main_function->show();
    atm_main_function->move(
        (QApplication::desktop()->width()  - atm_main_function->width())  / 2,
        (QApplication::desktop()->height() - atm_main_function->height()) / 2);
    this->close();
}
