#include "bar.h"

Bar::Bar(int id, QObject *parent) : QObject(parent)
{
    this->id = id;
}

void Bar::process()
{
    qDebug() << "Bar #" << id << "processing";
    QThread::sleep(1);
    emit finished(id);
}
