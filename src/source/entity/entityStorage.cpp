#include <entity/entityStorage.hpp>

#include <iostream>

std::vector<Entity *> EntityStorage::entities;
std::vector<Entity *> EntityStorage::buffer;

EntityStorage::EntityStorage() {}

EntityStorage::~EntityStorage() {}

void EntityStorage::add(Entity *entity)
{
    buffer.push_back(entity);
}

void EntityStorage::updateEntities()
{
    for (auto it = entities.begin(); it != entities.end();)
    {
        (*it)->onUpdate();
        if ((*it)->isDead())
        {
            Entity *ref = *it;
            entities.erase(it);
            delete (ref);
        }
        else
            ++it;
    }
    for (auto it = buffer.begin(); it != buffer.end();)
    {
        entities.insert(entities.begin(), *it);
        buffer.erase(it);
    };
}

void EntityStorage::drawEntities()
{
    for (Entity *entity : entities)
        entity->onDraw();
}