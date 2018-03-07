#ifndef REGULARCLASS_H
#define REGULARCLASS_H

#include <qthread.h>
#include <qobject.h>
#include <qdebug.h>


class RegularClass : public QObject
{
    Q_OBJECT
public:
    RegularClass() { }
public slots:
    void goooo();
signals:
    void finished();
};

#endif // REGULARCLASS_H
