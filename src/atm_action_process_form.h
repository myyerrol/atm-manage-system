#ifndef ATM_ACTION_PROCESS_FORM_H
#define ATM_ACTION_PROCESS_FORM_H

#include <QWidget>

namespace Ui {
class ATMActionProcessForm;
}

class ATMActionProcessForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMActionProcessForm(QWidget *parent = 0);
    ~ATMActionProcessForm();

private slots:
    void updateTimerOperation();

private:
    Ui::ATMActionProcessForm *ui;
    bool flag_stop_timer_;
};

#endif // ATM_ACTION_PROCESS_FORM_H
