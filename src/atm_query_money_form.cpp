#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDesktopWidget>
#include "atm_query_money_form.h"
#include "atm_main_function_form.h"
#include "ui_atm_query_money_form.h"

extern QString g_card_id;

ATMQueryMoneyForm::ATMQueryMoneyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMQueryMoneyForm)
{
    ui->setupUi(this);
    this->setWindowTitle("查询界面");
    this->setFixedSize(this->width(), this->height());

    QString tables = " user_information, card_information ";
    QString properties =
        " user_name, user_information.card_id, card_pwd, card_money ";
    QString condition_a =
       " user_information.card_id = card_information.card_id ";
    QString condition_b = " user_information.card_id = ";

    QSqlQueryModel *card_info_query_model = new QSqlQueryModel();
    card_info_query_model->setQuery("select" + properties + "from" + tables +
                                    "where"  + condition_a + "and" +
                                    condition_b + g_card_id);
    card_info_query_model->setHeaderData(0, Qt::Horizontal, tr("用户名"));
    card_info_query_model->setHeaderData(1, Qt::Horizontal, tr("银行卡账号"));
    card_info_query_model->setHeaderData(2, Qt::Horizontal, tr("银行卡密码"));
    card_info_query_model->setHeaderData(3, Qt::Horizontal, tr("银行卡金额"));

    ui->table_view_query_money->setEditTriggers(
        QAbstractItemView::NoEditTriggers);
    ui->table_view_query_money->setModel(card_info_query_model);
    ui->table_view_query_money->setColumnWidth(0, 135);
    ui->table_view_query_money->setColumnWidth(1, 135);
    ui->table_view_query_money->setColumnWidth(2, 135);
    ui->table_view_query_money->setColumnWidth(3, 135);
    ui->table_view_query_money->show();
}

ATMQueryMoneyForm::~ATMQueryMoneyForm()
{
    delete ui;
}

void ATMQueryMoneyForm::on_button_return_clicked()
{
    ATMMainFunctionForm *atm_main_function = new ATMMainFunctionForm();
    atm_main_function->show();
    atm_main_function->move(
        (QApplication::desktop()->width()  - atm_main_function->width())  / 2,
        (QApplication::desktop()->height() - atm_main_function->height()) / 2);
    this->close();
}
