#include "atm_connect_database.h"

QSqlDatabase ATMConnectDatabase::mysql_db =
    QSqlDatabase::addDatabase("QMYSQL");

ATMConnectDatabase::ATMConnectDatabase()
{
}

ATMConnectDatabase::~ATMConnectDatabase()
{
}

bool ATMConnectDatabase::openDatabase()
{
    mysql_db.setHostName("localhost");
    mysql_db.setDatabaseName("automatic_teller_machine_system");
    mysql_db.setUserName("root");
    mysql_db.setPassword("root");
    mysql_db.setPort(3306);

    if (mysql_db.open()) {
        return true;
    }
    else {
        return false;
    }
}

void ATMConnectDatabase::closeDatabase()
{
    mysql_db.close();
}

