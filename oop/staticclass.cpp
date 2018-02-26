#include "staticclass.h"

QList<int> StaticClass::list = QList<int> () << 1 << 2 << 3;

int StaticClass::x = 10;

int StaticClass::getX()
{
    return x;
}

void StaticClass::setX(int value)
{
    x = value;
}

void StaticClass::printHello()
{
    qDebug() << "Hello";
}
