#include <projectile.hpp>
#include <raylib-cpp.hpp>

#include <iostream>

// ---------------- Exhaust

ExhaustParticle::ExhaustParticle(Vector2 startPosition, float direction, Entity *origin)
{
    position = startPosition;
    this->direction = direction;
}

ExhaustParticle::~ExhaustParticle()
{
}

void ExhaustParticle::onUpdate()
{
    float new_x = position.x + speed * cos(direction * PI / 180);
    float new_y = position.y + speed * sin(direction * PI / 180);
    position.x = new_x;
    position.y = new_y;
    power--;
}

void ExhaustParticle::onDraw()
{
    DrawCircle(position.x, position.y, power, ORANGE);
    DrawCircle(position.x, position.y, power - 2, YELLOW);
}

bool ExhaustParticle::isDead()
{
    return power <= 0;
}

// ---------------- Bullet

Bullet::Bullet(Vector2 startPosition, float direction, Entity *origin)
{
    position = startPosition;
    this->direction = direction;
}

Bullet::~Bullet()
{
}

void Bullet::onUpdate()
{
    float new_x = position.x + speed * cos(direction * PI / 180);
    float new_y = position.y + speed * sin(direction * PI / 180);
    position.x = new_x;
    position.y = new_y;
    power--;
}

void Bullet::onDraw()
{
    DrawCircle(position.x, position.y, 3, {252, 252, 61, 255});
}

bool Bullet::isDead()
{
    return power <= 0;
}