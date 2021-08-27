#pragma once
#include <util/entity.hpp>
#include <vector>
#include <projectile/projectile.hpp>

class PlayerState;

class Player : public Entity
{
    friend class PlayerState;

public:
    Player();
    ~Player();
    void onUpdate();
    void onDraw();
    void doMovement();
    void shoota();

    Camera2D *camera;

private:
    void handleInput();
    void rotateToCursor();

    PlayerState *state;
    Texture2D spaceship;
    float rotation;
    float maxSpeed = 10;
    int acceleration = 0;
    std::vector<Projectile> bullets;
};