#include <character/character.hpp>
#include <character/characterStates.hpp>
#include <raylib-cpp.hpp>

#include <iostream>

Character::Character()
{
    state = static_cast<AbsCharState *>(new Idle());
    state->onEntry(*this);
    king = {position.x, position.y, 20, 20};
}

void Character::onUpdate() { state->onUpdate(*this); }

void Character::onDraw() {
    DrawRectangleRec(king, color);
}

void Character::setPosition(Vector2 position) {
    king.x = position.x;
    king.y = position.y;
}

Vector2 Character::getPosition() {
    return {king.x, king.y};
}

void Character::setColor(Color color) {
    this->color = color;
}

Character::~Character() { delete state; }