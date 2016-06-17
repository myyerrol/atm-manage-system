#include <QApplication>
#include <QDesktopWidget>
#include "atm_welcome_form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ATMWelcomeForm w;
    w.show();
    w.move((QApplication::desktop()->width()  - w.width())  / 2,
           (QApplication::desktop()->height() - w.height()) / 2);
    return a.exec();
}
