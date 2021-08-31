#pragma once
#include <util/entity.hpp>
#include <vector>
#include <projectile/projectile.hpp>

class PlayerState;

class Player : public Entity
{
    friend class PlayerState;

public:
Player(Camera2D *camera);
    ~Player();
    void onUpdate();
    void onDraw();
    void doMovement();
    void shoota();


private:
    void handleInput();
    void rotateToCursor();

    Camera2D *camera;
    PlayerState *state;
    Texture2D spaceship;
    float rotation;
    float maxSpeed = 10;
    int acceleration = 0;
    std::vector<Projectile> bullets;
};