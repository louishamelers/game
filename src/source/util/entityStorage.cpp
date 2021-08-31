#include <util/entityStorage.hpp>

std::vector<Entity *> EntityStorage::entities;

EntityStorage::EntityStorage() {}

EntityStorage::~EntityStorage() {}

void EntityStorage::add(Entity* entity) {
    entities.push_back(entity);
}

void EntityStorage::updateEntities() {
    for (Entity *entity : entities)
        entity->onUpdate();
}

void EntityStorage::drawEntities() {
    for (Entity *entity : entities)
        entity->onDraw();
}