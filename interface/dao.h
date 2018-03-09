#ifndef DAO_H
#define DAO_H

template <class T>
class Dao
{
public:
    virtual void create(T entity) = 0;
    virtual T read(int id) = 0;
    virtual void update(int id) = 0;
    virtual void remove(int id) = 0;
    /* В интерфейсах объявление виртуального дестуктора ОБЯЗАТЕЛЬНО.
       Т.к. если его не будет - при обходе дочерних объектов через тип Dao *
       в реализующем классе дестуктор НЕ БУДЕТ вызываться, т.к. интерфейс
       ничего не знает о дестукторе реализующего его класса!!! */
    virtual ~Dao() { }
};

#endif // DAO_H
