#include "../../headers/characterStateMachine/character.hpp"
#include "../../headers/characterStateMachine/characterStates.hpp"

Character::Character(raylib::Physics *physics)
{
    state = static_cast<AbsCharState *>(new Idle());
    physicsBody = physics->CreateBodyRectangle(position, 20.0f, 20.0f, 1);
    // physicsBody->freezeOrient = true;
}

void Character::movementInput(int direction) { state->moveInput(*this, direction); }

void Character::jumpInput(bool jump) { state->jumpInput(*this, jump); }

Character::~Character() { delete state; }