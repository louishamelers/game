#pragma once
#include <util/entity.hpp>
#include <Vector2.hpp>

class Projectile : public Entity
{
public:
    Projectile(Vector2 startPosition, float direction, Entity *origin, int acceleration);
    ~Projectile();
    void onUpdate();
    void onDraw();

    int speed;
    float direction;

};
