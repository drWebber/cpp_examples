#ifndef ENTITYDAO_H
#define ENTITYDAO_H

#include "dao.h"
#include "entity.h"

class EntityDao : public Dao<Entity>
{
public:
    virtual Entity getLastById(int id) = 0;
};

#endif // ENTITYDAO_H
