#include "staticclass.h"

#include <QCoreApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Статические классы */

    StaticClass::printHello();

    qDebug() << StaticClass::getX();
    StaticClass::setX(11);
    qDebug() << StaticClass::getX();


    return a.exec();
}
