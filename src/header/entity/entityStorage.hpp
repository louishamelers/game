#pragma once
#include <vector>
#include <entity/entity.hpp>

class EntityStorage
{
public:
    EntityStorage(/* args */);
    ~EntityStorage();
    static void updateEntities();
    static void drawEntities();
    static void add(class Entity* entity);
private:
    static std::vector<Entity *> entities;
    static std::vector<Entity *> buffer;
};