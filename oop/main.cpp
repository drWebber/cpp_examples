#include "staticclass.h"

#include <QCoreApplication>
#include <qdebug.h>

#include "overriding/foo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* Статические классы */

    StaticClass::printHello();

    qDebug() << StaticClass::getX();
    StaticClass::setX(11);
    qDebug() << StaticClass::getX();

    /* Перегрузка операторов */

    overriding::Foo foo1(1, "vasya");
    overriding::Foo foo2(1, "vasya");

    if (foo1 == foo2) {
        qDebug() << "foo1: " << foo1;
        qDebug() << "foo2: " << foo2;
        qDebug() << "foo1 == foo2";
    }

    foo2.setName("senya");
    if (foo1 != foo2) {
        qDebug() << "foo1: " << foo1;
        qDebug() << "foo2: " << foo2;
        qDebug() << "foo1 != foo2";
    }

    foo1.setId(2);
    if (foo1 > foo2) {
        qDebug() << "foo1: " << foo1;
        qDebug() << "foo2: " << foo2;
        qDebug() << "foo1 > foo2";
    }

    foo2.setId(3);
    if (foo1 < foo2) {
        qDebug() << "foo1: " << foo1;
        qDebug() << "foo2: " << foo2;
        qDebug() << "foo1 < foo2";
    }

    qDebug() << qHash(foo2);

    return a.exec();
}
