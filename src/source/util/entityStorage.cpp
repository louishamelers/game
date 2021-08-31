#include <util/entityStorage.hpp>

std::vector<Entity *> EntityStorage::entities;

EntityStorage::EntityStorage() {}

EntityStorage::~EntityStorage() {}

void EntityStorage::add(Entity* entity) {
    entities.push_back(entity);
}

std::vector<Entity *>* EntityStorage::getEntities() {
    return &entities;
}