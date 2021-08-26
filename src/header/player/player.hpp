#pragma once
#include <entity/entity.hpp>

class PlayerState;

class Player : public Entity
{
    friend class PlayerState;

public:
    Player();
    void onUpdate();
    void onDraw();
    ~Player();

    raylib::Vector2 position = {0, 0};
    Camera2D *camera;

private:
    void handleInput();

    const int maxSpeed = 10;

    PlayerState *state;
    Texture2D spaceship;
    int rotation;
    int acceleration = 0;
};