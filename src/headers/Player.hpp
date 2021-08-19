#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <Physics.hpp>

class Player
{
private:

public:
    PhysicsBody physicsBody;
    Vector2 position{0, 0};

    Player(raylib::Physics *physics)
    {
        physicsBody = (*physics).CreateBodyRectangle(position, 50, 50, 1);
        physicsBody->freezeOrient = true; // Constrain body rotation to avoid little collision torque amounts
    }

    void handleInput(const float velocity)
    {
        // Horizontal movement input
        if (IsKeyDown(KEY_RIGHT))
            physicsBody->velocity.x = velocity;
        else if (IsKeyDown(KEY_LEFT))
            physicsBody->velocity.x = -velocity;

        // Vertical movement input checking if player physics body is grounded
        if (IsKeyDown(KEY_UP) && physicsBody->isGrounded)
            physicsBody->velocity.y = -velocity * 4;
    }
};

#endif