#ifndef STATICCLASS_H
#define STATICCLASS_H

#include <qlist.h>
#include <qdebug.h>

class StaticClass
{
private:
    static int x;           // в .h только определение переменных,
                            // инициализация в .cpp
    static QList<int> list;
public:
    StaticClass();

    static void printHello(); // в .h пишется ключ static в .cpp нет

    static int getX();
    static void setX(int value);
};

#endif // STATICCLASS_H
