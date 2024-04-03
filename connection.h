#pragma once
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

inline bool createConnection() 
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("admin");
    db.setPort(5432);
    db.setHostName("localhost");
    if (!db.open())
    {
        QMessageBox::warning(0, "DB problems", db.lastError().text());
        return false;
    }
    else
    {
        return true;
    }
}

