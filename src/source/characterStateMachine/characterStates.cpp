#include "../../headers/characterStateMachine/characterStates.hpp"
#include "../../headers/characterStateMachine/character.hpp"
#include <Physics.hpp>
#include <iostream>

AbsCharState::~AbsCharState() = default;

void AbsCharState::setState(Character &character, AbsCharState *state)
{
    AbsCharState *aux = character.state;
    character.state = state;
    delete aux;
}

// Actual states:

Idle::~Idle() = default;

void Idle::moveInput(Character &character, int direction) {
    if (direction != 0) std::cout << "moving\n";
    setState(character, new Idle());
}

void Idle::jumpInput(Character &character, bool jump) {
    std::cout << "jumping\n";
}