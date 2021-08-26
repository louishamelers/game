#include <player/player.hpp>
#include <player/playerStates.hpp>
#include <iostream>
#include <Vector2.hpp>

PlayerState::~PlayerState() = default;

void PlayerState::setState(Player &character, PlayerState *state)
{
    PlayerState *aux = character.state;
    character.state = state;
    state->onEntry(character);
    delete aux;
}

// Actual states:

// Idle state
//----------------------------------------------------------------------------------
Idle::~Idle() = default;

void Idle::onUpdate(Player &character)
{
        Vector2 direction = {0, 0};
        if (IsKeyDown(KEY_RIGHT))
            setState(character, new Moving({1, 0}));
        if (IsKeyDown(KEY_LEFT))
            setState(character, new Moving({-1, 0}));
        if (IsKeyDown(KEY_UP))
            setState(character, new Moving({0, -1}));
        if (IsKeyDown(KEY_DOWN))
            setState(character, new Moving({0, 1}));
}

void Idle::onEntry(Player &character)
{
    // character.setColor(GRAY);
}

// Moving state
//----------------------------------------------------------------------------------
Moving::~Moving() = default;

Moving::Moving(Vector2 direction)
{
    this->direction = direction;
}

void Moving::onUpdate(Player &character)
{
    if (frames <= 20)
    {
        Vector2 newPosition = character.position;
        newPosition.x += direction.x;
        newPosition.y += direction.y;
        frames++;
    }
    else
    {
        setState(character, new Triggered());
    }
}

void Moving::onEntry(Player &character)
{
    // character.setColor(GREEN);
}

// Triggered state
//----------------------------------------------------------------------------------
Triggered::~Triggered() = default;

void Triggered::onUpdate(Player &character)
{
    frames++;
    if (frames >= 20)
        setState(character, new Idle());
}

void Triggered::onEntry(Player &character)
{
    // character.setColor(RED);
}