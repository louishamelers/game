#pragma once
#include <entity/entity.hpp>

class AbsCharState;

class Character : public Entity
{
    friend class AbsCharState;

public:
    Character();
    void onUpdate();
    void onDraw();
    ~Character();

    raylib::Vector2 position = {0, 0};
    Camera2D *camera;

private:
    void handleInput();

    const int maxSpeed = 10;

    AbsCharState *state;
    Texture2D spaceship;
    int rotation;
    int acceleration = 0;
};