#include <QDesktopWidget>
#include "atm_welcome_form.h"
#include "atm_login_to_main_form.h"
#include "ui_atm_welcome_form.h"

ATMWelcomeForm::ATMWelcomeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMWelcomeForm)
{
    ui->setupUi(this);
    this->setWindowTitle("欢迎界面");
    this->setFixedSize(this->width(), this->height());
}

ATMWelcomeForm::~ATMWelcomeForm()
{
    delete ui;
}

void ATMWelcomeForm::on_button_exit_clicked()
{
    this->close();
}

void ATMWelcomeForm::on_button_enter_clicked()
{
    ATMLoginToMainForm *atm_login_to_main = new ATMLoginToMainForm();
    atm_login_to_main->show();
    atm_login_to_main->move(
        (QApplication::desktop()->width()  - atm_login_to_main->width())  / 2,
        (QApplication::desktop()->height() - atm_login_to_main->height()) / 2);
    this->close();
}
