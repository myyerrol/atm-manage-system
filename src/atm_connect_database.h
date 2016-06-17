#ifndef CONNECT_DATABASE_H
#define CONNECT_DATABASE_H

#include <QSqlDatabase>

class ATMConnectDatabase
{
public:
    ATMConnectDatabase();
    ~ATMConnectDatabase();
    static bool openDatabase();
    static void closeDatabase();
private:
    static QSqlDatabase mysql_db;
};

#endif // CONNECT_DATABASE_H
