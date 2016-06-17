#include <QString>
#include <QDebug>
#include <QTimer>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDesktopWidget>
#include "atm_save_money_form.h"
#include "atm_main_function_form.h"
#include "atm_action_process_form.h"
#include "ui_atm_save_money_form.h"

extern QString g_card_id;
bool           g_save_money;

ATMSaveMoneyForm::ATMSaveMoneyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMSaveMoneyForm)
{
    ui->setupUi(this);
    this->setWindowTitle("存款界面");
    this->setFixedSize(this->width(), this->height());

    QPalette palette_text = ui->text_browser_info->palette();
    palette_text.setBrush(QPalette::Base, QBrush(Qt::NoBrush));
    ui->text_browser_info->setPalette(palette_text);
    QPalette palette_lcd;
    palette_lcd.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);
    ui->lcd_timer->setPalette(palette_lcd);
    ui->lcd_timer->setSegmentStyle(QLCDNumber::Flat);
    ui->lcd_timer->display(30);

    flag_return_     = false;
    flag_stop_timer_ = false;

    QTimer *timer_ = new QTimer(this);
    timer_->start(1000);
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateTimerOperation()));
}

ATMSaveMoneyForm::~ATMSaveMoneyForm()
{
    delete ui;
}

void ATMSaveMoneyForm::startNewWindow(QWidget *new_window)
{
    new_window->show();
    new_window->move(
        (QApplication::desktop()->width()  - new_window->width())  / 2,
        (QApplication::desktop()->height() - new_window->height()) / 2);
}

bool ATMSaveMoneyForm::getAllCardMoney(int &money_all)
{
    QString table     = " card_information ";
    QString property  = " card_money ";
    QString condition = " card_id = " + g_card_id;

    QSqlQuery query;
    query.exec("select" + property + "from" + table + "where" + condition);

    int        index;
    QSqlRecord record;

    if (query.next()) {
        record = query.record();
        index  = record.indexOf("card_money");
        money_all = query.value(index).toInt();
        return true;
    }
    else {
        return false;
    }
}

bool ATMSaveMoneyForm::saveMoneyToATM(int money_save, int money_all)
{
    QString money_rest = QString::number((money_all + money_save), 10);
    QString table      = " card_information ";
    QString property   = " card_money ";
    QString condition  = " card_id = " + g_card_id;

    QSqlQuery query;
    query.exec("update" + table + "set" + property + "=" + money_rest + " where"
               + condition);

    if (query.isActive()) {
        return true;
    }
    else {
        return false;
    }
}

void ATMSaveMoneyForm::saveMoneyOperation(int money_save)
{
    int money_all;

    if (getAllCardMoney(money_all)) {
        ATMActionProcessForm *atm_action_process = new ATMActionProcessForm();
        startNewWindow(atm_action_process);
        ui->lcd_timer->display(30);
        g_save_money = saveMoneyToATM(money_save, money_all);
    }
    else {
        QMessageBox::warning(this, tr("错误"), tr("没有可用余额！"), tr("是"));
        ui->lcd_timer->display(30);
    }
}

void ATMSaveMoneyForm::on_button_100_clicked()
{
    saveMoneyOperation(100);
}

void ATMSaveMoneyForm::on_button_200_clicked()
{
    saveMoneyOperation(200);
}

void ATMSaveMoneyForm::on_button_400_clicked()
{
    saveMoneyOperation(400);
}

void ATMSaveMoneyForm::on_button_800_clicked()
{
    saveMoneyOperation(800);
}

void ATMSaveMoneyForm::on_button_1000_clicked()
{
    saveMoneyOperation(1000);
}

void ATMSaveMoneyForm::on_button_2000_clicked()
{
    saveMoneyOperation(2000);
}

void ATMSaveMoneyForm::on_button_accept_clicked()
{
    QString money = ui->line_edit_money->text();
    saveMoneyOperation(money.toInt());
}

void ATMSaveMoneyForm::on_button_return_clicked()
{
    ATMMainFunctionForm *atm_main_function = new ATMMainFunctionForm();
    startNewWindow(atm_main_function);
    flag_stop_timer_ = true;
    this->close();
}

void ATMSaveMoneyForm::updateTimerOperation()
{
    if (flag_stop_timer_) {
        return ;
    }
    if (ui->lcd_timer->intValue() > 0) {
        flag_return_ = false;
        ui->lcd_timer->display(ui->lcd_timer->intValue() - 1);
    }
    else {
        if (!flag_return_) {
            flag_return_ = true;
            ATMMainFunctionForm *atm_main_function = new ATMMainFunctionForm();
            startNewWindow(atm_main_function);
            this->close();
        }
    }
}
