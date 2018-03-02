#ifndef FOO_H
#define FOO_H

#include <qstring.h>
#include <QtCore/qhash.h>

class Foo
{
private:
    int id;
    QString name;
public:
    Foo(int id, QString name);

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    operator QString();
};

inline operator ==(Foo const &obj1, Foo const &obj2) {
    return obj1.getId() == obj2.getId() && obj1.getName() == obj2.getName();
}

inline uint qHash(const Foo &foo, uint seed = 0)
{
    return ::qHash(foo.getName(), seed);
}

#endif // FOO_H
