#include "foo.h"


Foo::Foo(int id, QObject *parent) : QThread(parent)
{
    this->id = id;
}

void Foo::run()
{
    while (1) {
        QThread::sleep(1);
        qDebug() << "hello from #" << id;
    }
}
