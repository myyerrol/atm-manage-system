#ifndef ATM_TRANSFER_MONEY_FORM_H
#define ATM_TRANSFER_MONEY_FORM_H

#include <QWidget>

namespace Ui {
class ATMTransferMoneyForm;
}

class ATMTransferMoneyForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMTransferMoneyForm(QWidget *parent = 0);
    ~ATMTransferMoneyForm();

private slots:
    void on_button_accept_a_clicked();
    void on_button_accept_b_clicked();
    void on_button_reset_clicked();
    void on_button_return_clicked();

private:
    Ui::ATMTransferMoneyForm *ui;
};

#endif // ATM_TRANSFER_MONEY_FORM_H
