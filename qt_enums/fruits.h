#ifndef FRUITS_H
#define FRUITS_H

#include <QObject>
#include <qmetaobject.h>

class Fruits : public QObject
{
    Q_OBJECT
    Q_ENUMS(Fruit)
public:
    explicit Fruits(QObject *parent = 0);
    enum Fruit {APPLE, LEMON, BANANA};
    static int keyToValue(QString key);
    static QString valueToKey(int value);
};

#endif // FRUITS_H
