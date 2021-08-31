#pragma once
#include <Vector2.hpp>

class Entity
{
public:
    virtual void onUpdate() = 0;
    virtual void onDraw() = 0;
    virtual bool isDead() = 0;
    
    Vector2 position = {0,0};
};