#ifndef ATM_WELCOME_FORM_H
#define ATM_WELCOME_FORM_H

#include <QWidget>

namespace Ui {
class ATMWelcomeForm;
}

class ATMWelcomeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMWelcomeForm(QWidget *parent = 0);
    ~ATMWelcomeForm();

private slots:
    void on_button_exit_clicked();
    void on_button_enter_clicked();

private:
    Ui::ATMWelcomeForm *ui;
};

#endif // ATM_WELCOME_FORM_H
