#include "foo.h"

Foo::Foo(int id, QString name)
{
    this->id = id;
    this->name = name;
}

int Foo::getId() const
{
    return id;
}

void Foo::setId(int value)
{
    id = value;
}

QString Foo::getName() const
{
    return name;
}

void Foo::setName(const QString &value)
{
    name = value;
}

Foo::operator QString()
{
    return "id = " + QString::number(id) + "; name = " + name;
}

