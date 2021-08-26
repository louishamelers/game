#pragma once
#include <entity/entity.hpp>

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

    raylib::Vector2 position = {0, 0};
    Camera2D *camera;

private:
    void handleInput();
    void rotateToCursor();

    PlayerState *state;
    Texture2D spaceship;
    float rotation;
    float maxSpeed = 10;
    int acceleration = 0;
};