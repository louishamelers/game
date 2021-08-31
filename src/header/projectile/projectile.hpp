#pragma once
#include <util/entity.hpp>
#include <Vector2.hpp>

class Projectile : public Entity
{
public:
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
    virtual bool isDead() = 0;

private:
    int speed;
    float direction;
    int power;
};

class ExhaustParticle : public Projectile
{
public:
    ExhaustParticle(Vector2 startPosition, float direction, Entity *origin);
    ~ExhaustParticle();
    void onUpdate();
    void onDraw();
    bool isDead();


private:
    float direction;
    int speed = 1;
    int power = 8;
};

class Bullet : public Projectile
{
public:
    Bullet(Vector2 startPosition, float direction, Entity *origin);
    ~Bullet();
    void onUpdate();
    void onDraw();
    bool isDead();


private:
    float direction;
    int speed = 10;
    int power = 200;
};