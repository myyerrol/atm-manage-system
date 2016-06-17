#ifndef ATM_MAIN_FUNCTION_FORM_H
#define ATM_MAIN_FUNCTION_FORM_H

#include <QWidget>

namespace Ui {
class ATMMainFunctionForm;
}

class ATMMainFunctionForm : public QWidget
{
    Q_OBJECT

public:
    explicit ATMMainFunctionForm(QWidget *parent = 0);
    ~ATMMainFunctionForm();

private:
    void startNewWindow(QWidget *new_window);

private slots:
    void on_button_query_money_clicked();
    void on_button_transfer_money_clicked();
    void on_button_change_pwd_clicked();
    void on_button_save_money_clicked();
    void on_button_take_money_clicked();
    void on_button_return_clicked();
    void updateTimerOperation();

private:
    Ui::ATMMainFunctionForm *ui;
    bool     flag_return_;
    bool     flag_stop_timer_;
    QTimer   *timer_;
    QPalette palette_text_;
    QPalette palette_lcd_;
};

#endif // ATM_MAIN_FUNCTION_FORM_H
