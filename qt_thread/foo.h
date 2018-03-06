#ifndef FOO_H
#define FOO_H

#include <qthread.h>
#include <qdebug.h>

class Foo : public QThread
{
    Q_OBJECT
private:
    int id;

    // QThread interface
protected:
    void run() override;
public:
    Foo(int id, QObject *parent = nullptr);
    void bar();
};

#endif // FOO_H
