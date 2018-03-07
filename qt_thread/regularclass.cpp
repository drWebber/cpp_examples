#include "regularclass.h"


void RegularClass::goooo()
{
    for (int i = 0; i < 5; ++i) {
        qDebug() << "i:" << i;
    }
    emit finished();
}
