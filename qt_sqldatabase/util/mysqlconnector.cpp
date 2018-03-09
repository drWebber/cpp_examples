#include "mysqlconnector.h"


QSqlDatabase MySqlConnector::getConnection(QString connectionName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3", connectionName);
    db.setHostName("localhost");
    db.setDatabaseName("dbname");
    db.setUserName("root");
    db.setPassword("password");
    return db;
}

void MySqlConnector::setConnectionEncodingCP1251(QSqlDatabase db)
{
    QSqlQuery query(db);

    /* SET NAMES x эквивалентен следующей группе:
     * character_set_client - кодировка в которой посылается запрос от клиента
     * character_set_connection - кодировка используемая для конвертации
     *      пришедшего запроса (statement'а)
     * character_set_results - кодировку, в которую сервер должен перевести
     *      результат перед его отправкой клиенту
     * character_set_database — кодировка по умолчанию для баз
     */
    query.exec("SET character_set_client=cp1251");
    query.exec("SET character_set_connection=UTF8");
    query.exec("SET character_set_results=cp1251");

    query.exec("SET character_set_database=UTF8");
}
