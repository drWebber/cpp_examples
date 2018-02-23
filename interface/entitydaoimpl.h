#ifndef ENTITYDAOIMPL_H
#define ENTITYDAOIMPL_H

#include "entitydao.h"

#include <iostream>

using namespace std;

class EntityDaoImpl : public EntityDao
{
    // Dao interface
public:
    void create(Entity entity);
    Entity read(int id);
    void update(int id);
    void remove(int id);

    // EntityDao interface
public:
    Entity getLastById(int id);
};

#endif // ENTITYDAOIMPL_H
