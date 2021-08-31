#pragma once
#include <vector>
#include <projectile/projectile.hpp>
#include <util/entity.hpp>

class ProjectileStorage : public Entity
{
public:
    ProjectileStorage();
    ~ProjectileStorage();
    void onUpdate();
    void onDraw();
    static void add(class Projectile* projectile);
    static void add(const std::vector<Projectile*>& newProjectiles);
    void prune();
private:
    static std::vector<Projectile*> projectiles;
};