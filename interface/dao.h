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
};

#endif // DAO_H
