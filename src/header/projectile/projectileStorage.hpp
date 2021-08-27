#pragma once
#include <vector>
#include <projectiles/projectile.hpp>

class projectileStorage
{
public:
    projectileStorage();
    ~projectileStorage();
    static void add(class Projectile* projectile);
    static void add(const std::vector<Projectile*>& newProjectiles);
    void prune();
private:
    static std::vector<Projectile*> projectiles;
};