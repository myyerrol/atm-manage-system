#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDesktopWidget>
#include "atm_change_password_form.h"
#include "atm_main_function_form.h"
#include "ui_atm_change_password_form.h"

extern QString g_card_id;
extern QString g_card_pwd;

ATMChangePasswordForm::ATMChangePasswordForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMChangePasswordForm)
{
    ui->setupUi(this);
    this->setWindowTitle("改密界面");
    this->setFixedSize(this->width(), this->height());
}

ATMChangePasswordForm::~ATMChangePasswordForm()
{
    delete ui;
}

void ATMChangePasswordForm::on_button_accept_clicked()
{
    QString card_pwd_new_a;
    QString card_pwd_new_b;
    QString table = " card_information ";

    card_pwd_new_a = ui->line_edit_card_pwd_new_a->text();
    card_pwd_new_b = ui->line_edit_card_pwd_new_b->text();

    if (card_pwd_new_a == card_pwd_new_b && card_pwd_new_a != g_card_pwd) {
        QSqlQuery query;
        query.prepare("update" + table +
                      "set card_pwd = :card_pwd where card_id = :card_id");
        query.bindValue(":card_pwd", card_pwd_new_a);
        query.bindValue(":card_id", g_card_id);
        query.exec();
        if (query.isActive()) {
            QMessageBox::information(this, tr("提示"), tr("密码已修改！"),
                                     tr("是"));
            ATMMainFunctionForm *atm_main_function = new ATMMainFunctionForm();
            atm_main_function->show();
            atm_main_function->move(
                (QApplication::desktop()->width()  -
                 atm_main_function->width())  / 2,
                (QApplication::desktop()->height() -
                 atm_main_function->height()) / 2);
            this->close();
        }
    }
    else {
        QMessageBox::warning(this, tr("警告"), tr("两次输入的密码不正确！"),
                             tr("是"));
        ui->line_edit_card_pwd_new_a->clear();
        ui->line_edit_card_pwd_new_b->clear();
    }
}

void ATMChangePasswordForm::on_button_reset_clicked()
{
    ui->line_edit_card_pwd_new_a->clear();
    ui->line_edit_card_pwd_new_b->clear();
}

void ATMChangePasswordForm::on_button_return_clicked()
{
    ATMMainFunctionForm *atm_main_function = new ATMMainFunctionForm();
    atm_main_function->show();
    atm_main_function->move(
        (QApplication::desktop()->width()  - atm_main_function->width())  / 2,
        (QApplication::desktop()->height() - atm_main_function->height()) / 2);
    this->close();
}
