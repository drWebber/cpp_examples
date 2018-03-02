#include "foo.h"

overriding::Foo::Foo(int id, QString name)
{
    this->id = id;
    this->name = name;
}

bool overriding::Foo::operator ==(const overriding::Foo &obj) const
{
    return id == obj.getId() && name == obj.getName();
}

bool overriding::Foo::operator <(const overriding::Foo &obj) const
{
    return id < obj.getId();
}

bool overriding::Foo::operator >(const overriding::Foo &obj) const
{
    return id > obj.getId();
}

bool overriding::Foo::operator !=(const overriding::Foo &obj) const
{
    return !(*this == obj);
}

uint overriding::Foo::qHash(const overriding::Foo &foo, uint seed)
{
    return ::qHash(foo.getName(), seed);
}

overriding::Foo::operator QString()
{
    return "id = " + QString::number(id) + "; name = " + name;
}

int overriding::Foo::getId() const
{
    return id;
}

void overriding::Foo::setId(int value)
{
    id = value;
}

QString overriding::Foo::getName() const
{
    return name;
}

void overriding::Foo::setName(const QString &value)
{
    name = value;
}
