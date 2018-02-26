#include "fruits.h"

int Fruits::keyToValue(QString key)
{
    QMetaEnum metaEnum = Fruits::staticMetaObject.
            enumerator(Fruits::staticMetaObject.indexOfEnumerator("Fruit"));
    return metaEnum.keysToValue(key.toLatin1().data());
}

QString Fruits::valueToKey(int value)
{
    QMetaEnum metaEnum = Fruits::staticMetaObject.
            enumerator(Fruits::staticMetaObject.indexOfEnumerator("Fruit"));
    return metaEnum.valueToKey(value);
}
