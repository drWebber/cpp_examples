#include "fruits.h"

#include <qdebug.h>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << Fruits::valueToKey(Fruits::APPLE);
    qDebug() << Fruits::keyToValue("APPLE");

    return a.exec();
}
