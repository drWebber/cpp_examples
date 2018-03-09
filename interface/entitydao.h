#ifndef ENTITYDAO_H
#define ENTITYDAO_H

#include "dao.h"
#include "entity.h"

class EntityDao : public Dao<Entity>
{
public:
    virtual Entity getLastById(int id) = 0;
    /* В интерфейсах объявление виртуального дестуктора ОБЯЗАТЕЛЬНО.
       Т.к. если его не будет - при обходе дочерних объектов через EntityDao *
       тип в реализующем классе дестуктор НЕ БУДЕТ вызываться, т.к. интерфейс
       ничего не знает о дестукторе реализующего его класса!!! */
    virtual ~EntityDao() { }
};

#endif // ENTITYDAO_H
