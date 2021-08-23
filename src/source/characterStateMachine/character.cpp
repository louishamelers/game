#include "../../headers/characterStateMachine/character.hpp"
#include "../../headers/characterStateMachine/characterStates.hpp"
#include <iostream>

Character::Character()
{
    state = static_cast<AbsCharState *>(new Idle());
    std::cout << "made\n";
}

Character::~Character() { delete state; }

void Character::movementInput(int direction) { state->moveInput(*this, direction); }

void Character::jumpInput(bool jump) { state->jumpInput(*this, jump); }