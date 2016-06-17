#ifndef ATM_CHANGE_PASSWORD_FORM_H
#define ATM_CHANGE_PASSWORD_FORM_H

#include <QWidget>

namespace Ui {
class ATMChangePasswordForm;
}

class ATMChangePasswordForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMChangePasswordForm(QWidget *parent = 0);
    ~ATMChangePasswordForm();

private slots:
    void on_button_accept_clicked();
    void on_button_reset_clicked();
    void on_button_return_clicked();

private:
    Ui::ATMChangePasswordForm *ui;
};

#endif // ATM_CHANGE_PASSWORD_FORM_H
