#include "util/mysqlconnector.h"

#include <QCoreApplication>
#include <quuid.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QUuid позволяет создать уникальноую строку QString
    QString connectionName = QUuid::createUuid().toString();

    QSqlDatabase db = MySqlConnector::getConnection(connectionName);
    MySqlConnector::setConnectionEncodingCP1251(db);

//    Для открытия соединения не забываем выполнить .OPEN()
    db.open();

//     Cоединения хранятся глобально, нужное соединение можно вынуть по имени
//    QSqlDatabase db2 = QSqlDatabase::database(connectionName);


    /* рабочий способ закрытия соединения: */
    db.close();
    db = QSqlDatabase();
//    removeDatabase необходимо вызвать именно статически, когда область
//    видимости QSqlDatabase db закончилась (в данном с присвоением ей пустого
//    объекта QSqlDatabase()), почему так - см. справку
    QSqlDatabase::removeDatabase(connectionName);

    return a.exec();
}
