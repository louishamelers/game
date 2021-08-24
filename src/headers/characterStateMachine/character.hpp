#pragma once
#include <Physics.hpp> 

class AbsCharState;

class Character
{
    friend class AbsCharState;

public:
    Character(raylib::Physics *physics);
    void movementInput(int direction);
    void jumpInput(bool jump);
    ~Character();

private:
    AbsCharState *state;
    PhysicsBodyData *physicsBody;
    Vector2 position{80,0};
};