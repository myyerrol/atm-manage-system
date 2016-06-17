#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include "atm_action_process_form.h"
#include "ui_atm_action_process_form.h"

extern bool g_take_money;
extern bool g_save_money;

ATMActionProcessForm::ATMActionProcessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ATMActionProcessForm)
{
    ui->setupUi(this);
    this->setWindowTitle("进程界面");
    this->setFixedSize(this->width(), this->height());

    flag_stop_timer_ = false;

    QTimer *timer_ = new QTimer(this);
    timer_->start(50);
    connect(timer_, SIGNAL(timeout()), this, SLOT(updateTimerOperation()));
}

ATMActionProcessForm::~ATMActionProcessForm()
{
    delete ui;
}

void ATMActionProcessForm::updateTimerOperation()
{
    if (flag_stop_timer_) {
        return ;
    }

    int process = ui->progress_bar->value() + 1;

    if (process <= 100) {
        flag_stop_timer_ = false;
        ui->progress_bar->setValue(process);
    }
    else {
        flag_stop_timer_ = true;
        if (g_take_money && !g_save_money) {
            g_take_money = false;
            QMessageBox::information(this, tr("提示"), tr("取款操作完成！"),
                                     tr("是"));
        }
        else if (!g_take_money && g_save_money) {
            g_save_money = false;
            QMessageBox::information(this, tr("提示"), tr("存款操作完成！"),
                                     tr("是"));
        }
        else if ((!g_take_money && !g_save_money)){
            QMessageBox::warning(this, tr("错误"), tr("操作未完成！"), tr("是"));
        }
        this->close();
    }
}
