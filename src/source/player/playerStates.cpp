#include <player/player.hpp>
#include <player/playerStates.hpp>
#include <iostream>
#include <Vector2.hpp>

PlayerState::~PlayerState() = default;

void PlayerState::setState(Player &player, PlayerState *state)
{
    PlayerState *aux = player.state;
    player.state = state;
    state->onEntry(player);
    delete aux;
}

// Actual states:

// Idle state
//----------------------------------------------------------------------------------
Healthy::~Healthy() = default;

void Healthy::shoot(Player &player)
{
    printf("PEW");
    DrawLine(player.position.x, player.position.y, 0, 0, RED);
    // Vector2 direction = {0, 0};
    // if (IsKeyDown(KEY_RIGHT))
    //     setState(player, new Moving({1, 0}));
    // if (IsKeyDown(KEY_LEFT))
    //     setState(player, new Moving({-1, 0}));
    // if (IsKeyDown(KEY_UP))
    //     setState(player, new Moving({0, -1}));
    // if (IsKeyDown(KEY_DOWN))
    //     setState(player, new Moving({0, 1}));
}

void Healthy::onEntry(Player &player)
{
    // player.setColor(GRAY);
}

// // Moving state
// //----------------------------------------------------------------------------------
// Moving::~Moving() = default;

// Moving::Moving(Vector2 direction)
// {
//     this->direction = direction;
// }

// void Moving::onUpdate(Player &player)
// {
//     if (frames <= 20)
//     {
//         Vector2 newPosition = player.position;
//         newPosition.x += direction.x;
//         newPosition.y += direction.y;
//         frames++;
//     }
//     else
//     {
//         setState(player, new Triggered());
//     }
// }

// void Moving::onEntry(Player &player)
// {
//     // player.setColor(GREEN);
// }

// // Triggered state
// //----------------------------------------------------------------------------------
// Triggered::~Triggered() = default;

// void Triggered::onUpdate(Player &player)
// {
//     frames++;
//     if (frames >= 20)
//         setState(player, new Idle());
// }

// void Triggered::onEntry(Player &player)
// {
//     // player.setColor(RED);
// }