#ifndef BAR_H
#define BAR_H

#include <qobject.h>
#include <qdebug.h>
#include <qthread.h>

class Bar : public QObject
{
    Q_OBJECT
private:
    int id;
public:
    Bar(int id, QObject *parent = nullptr);
public slots:
    void process();
signals:
    void finished(int);
};

#endif // BAR_H
