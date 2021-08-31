#include <projectile/projectileStorage.hpp>
#include <vector>

#include <iostream>

std::vector<Projectile *> ProjectileStorage::projectiles;

ProjectileStorage::ProjectileStorage(){};

ProjectileStorage::~ProjectileStorage() = default;

void ProjectileStorage::onUpdate()
{
    for (auto it = projectiles.begin(); it != projectiles.end();)
    {
        (*it)->onUpdate();
        if ((*it)->power <= 0)
        {
            Projectile *ref = *it;
            projectiles.erase(it);
            delete (ref);
        }
        else
            ++it;
    }
}

void ProjectileStorage::onDraw()
{
    for (Projectile *projectile : projectiles)
        projectile->onDraw();
}

void ProjectileStorage::add(Projectile *projectile)
{
    projectiles.push_back(projectile);
}