#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QDebug>
#include "atm_login_to_main_form.h"
#include "atm_main_function_form.h"
#include "atm_welcome_form.h"
#include "atm_connect_database.h"
#include "ui_atm_login_to_main_form.h"

QString g_card_id;
QString g_card_pwd;

ATMLoginToMainForm::ATMLoginToMainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMLoginToMainForm)
{
    ui->setupUi(this);
    this->setWindowTitle("登录界面");
    this->setFixedSize(this->width(), this->height());
}

ATMLoginToMainForm::~ATMLoginToMainForm()
{
    delete ui;
}

void ATMLoginToMainForm::on_button_login_clicked()
{
    bool flag_id  = false;
    bool flag_pwd = false;
    int index_card_id;
    int index_card_pwd;
    QString card_id;
    QString card_pwd;
    QSqlQuery query;
    QSqlRecord record;

    card_id = ui->line_edit_id->text();
    card_pwd   = ui->line_edit_pwd->text();

    if (!ATMConnectDatabase::openDatabase()) {
        QMessageBox::warning(this, tr("错误"), tr("打开数据库失败!"), tr("是"));
        return ;
    }

    query.exec("select * from card_information");

    while (query.next()) {
        record = query.record();
        index_card_id = record.indexOf("card_id");
        index_card_pwd   = record.indexOf("card_pwd");
        if (query.value(index_card_id).toString() == card_id) {
            flag_id = true;
            if (query.value(index_card_pwd).toString() == card_pwd) {
                g_card_id  = card_id;
                g_card_pwd = card_pwd;
                flag_pwd = true;
                ui->line_edit_id->clear();
                ui->line_edit_pwd->clear();
                ATMMainFunctionForm *atm_main_function =
                    new ATMMainFunctionForm();
                atm_main_function->show();
                atm_main_function->move(
                    (QApplication::desktop()->width()  -
                     atm_main_function->width())  / 2,
                    (QApplication::desktop()->height() -
                     atm_main_function->height()) / 2);
                this->close();
            }
        }
    }

    if (flag_id && !flag_pwd) {
        QMessageBox::warning(this, tr("错误"), tr("密码错误！"), tr("是"));
        ui->line_edit_pwd->clear();
        return ;
    }
    else if (!flag_id && !flag_pwd){
        QMessageBox::warning(this, tr("错误"), tr("账户或密码错误！"), tr("是"));
        ui->line_edit_id->clear();
        ui->line_edit_pwd->clear();
        return ;
    }
}

void ATMLoginToMainForm::on_button_return_clicked()
{
    ATMWelcomeForm *atm_welcome = new ATMWelcomeForm();
    atm_welcome->show();
    atm_welcome->move((QApplication::desktop()->width()  -
                       atm_welcome->width())  / 2,
                      (QApplication::desktop()->height() -
                       atm_welcome->height()) / 2);
    this->close();
}
