#pragma once
#include <Vector2.hpp>
#include <entity/entity.hpp>

class AbsCharState;

class Character : public Entity
{
    friend class AbsCharState;

public:
    Character();
    void onUpdate();
    void onDraw();
    void setPosition(Vector2 position);
    Vector2 getPosition();
    void setColor(Color color);
    ~Character();

    bool controllable = true;

private:
    AbsCharState *state;
    Rectangle king;
    Color color;
};