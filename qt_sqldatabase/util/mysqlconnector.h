#ifndef MYSQLCONNECTOR_H
#define MYSQLCONNECTOR_H

#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlerror.h>
#include <qsqlquery.h>

class MySqlConnector
{
public:
    static QSqlDatabase getConnection(
            QString connectionName = "qt_sql_default_connection");
    static void setConnectionEncodingCP1251(QSqlDatabase db);
};

#endif // MYSQLCONNECTOR_H
