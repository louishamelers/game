#pragma once
#include <vector>
#include <util/entity.hpp>

class EntityStorage
{
public:
    EntityStorage(/* args */);
    ~EntityStorage();
    static std::vector<Entity *>* getEntities();
    static void add(class Entity* entity);
private:
    static std::vector<Entity *> entities;
};