#ifndef ATM_TAKE_MONEY_FORM_H
#define ATM_TAKE_MONEY_FORM_H

#include <QWidget>

namespace Ui {
class ATMTakeMoneyForm;
}

class ATMTakeMoneyForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMTakeMoneyForm(QWidget *parent = 0);
    ~ATMTakeMoneyForm();

private:
    void startNewWindow(QWidget *new_window);
    bool isHaveEnoughMoney(int money_take, int &money_all);
    bool takeMoneyFromATM(int money_take, int money_all);
    void takeMoneyOperation(int money_take);

private slots:
    void on_button_100_clicked();
    void on_button_200_clicked();
    void on_button_400_clicked();
    void on_button_800_clicked();
    void on_button_1000_clicked();
    void on_button_2000_clicked();
    void on_button_accept_clicked();
    void on_button_return_clicked();
    void updateTimerOperation();

private:
    Ui::ATMTakeMoneyForm *ui;
    bool      flag_return_;
    bool      flag_stop_timer_;
};

#endif // ATM_TAKE_MONEY_FORM_H
