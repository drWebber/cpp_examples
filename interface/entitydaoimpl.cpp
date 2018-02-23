#include "entitydaoimpl.h"



void EntityDaoImpl::create(Entity entity)
{
    cout << "Creating the row " << entity.getId()  << endl;
}

Entity EntityDaoImpl::read(int id)
{
    cout << "Reading the row " << id  << endl;
    return Entity();
}

void EntityDaoImpl::update(int id)
{
    cout << "Updating the row " << id  << endl;
}

void EntityDaoImpl::remove(int id)
{
    cout << "Removing the row " << id  << endl;
}

Entity EntityDaoImpl::getLastById(int id)
{
    cout << "Getting the last row by id " << id  << endl;
    return Entity();
}
