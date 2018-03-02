#include <QCoreApplication>
#include <qset.h>
#include <qdebug.h>

#include "foo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* QSet<T> – неупорядоченное множество без повторений элементов
     * (только уникальных значений), основанное на хэш-таблице.
     * Множество позволяет быстро искать и добавлять значения,
     * элементы располагаются в несортированном порядке, причем порядок
     * после инициализации может быть каждый раз разный
     */

    QSet<int> primitiveSet = QSet<int>() << 1 << 1 << 2 << 3 << 110;
    qDebug() << primitiveSet;

    // Set, параметризованный кастомным классом
    // Для использования необходимо перегрузить operator ==
    // и uint qHash(const Foo &foo, uint seed = 0)
    QSet<Foo> set;
    set.insert(Foo(1, "vasya"));
    set.insert(Foo(2, "senya"));
    set.insert(Foo(2, "senya"));
    set.insert(Foo(3, "senya"));

    foreach (Foo f, set) {
        qDebug() << f;
    }

    return a.exec();
}
