#ifndef ATM_SAVE_MONEY_FORM_H
#define ATM_SAVE_MONEY_FORM_H

#include <QWidget>

namespace Ui {
class ATMSaveMoneyForm;
}

class ATMSaveMoneyForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMSaveMoneyForm(QWidget *parent = 0);
    ~ATMSaveMoneyForm();

private:
    void startNewWindow(QWidget *new_window);
    bool getAllCardMoney(int &money_all);
    bool saveMoneyToATM(int money_save, int money_all);
    void saveMoneyOperation(int money_save);

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
    Ui::ATMSaveMoneyForm *ui;
    bool      flag_return_;
    bool      flag_stop_timer_;
};

#endif // ATM_SAVE_MONEY_FORM_H
