#ifndef FOO_H
#define FOO_H

#include <qstring.h>


namespace overriding {

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

    bool operator ==(Foo const &obj) const;
    bool operator <(Foo const &obj) const;
    bool operator >(Foo const &obj) const;
    bool operator !=(Foo const &obj) const;
    operator QString();
};

}
#endif // FOO_H
