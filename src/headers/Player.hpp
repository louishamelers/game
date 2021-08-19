#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
#include <Physics.hpp>
#include "SpriteController.hpp"

// PlayerStates:
// 0 = idle
// 1 = moving
// 2 = jumping

enum State
{
    Idle,
    Moving,
    Jumping,
    Falling
};

class Player
{
public:
    PhysicsBody physicsBody;
    SpriteController spriteController;
    Vector2 position{0, 0};
    State playerState = Idle;
    int lookingDirection = 0;
    bool jumpPressed = false;

    Player(raylib::Physics *physics)
    {
        std::vector<int> tracks = {13, 8, 10, 10, 10, 6, 4, 7};
        spriteController = SpriteController(LoadTexture("assets/sprites/myboy.png"), tracks);
        physicsBody = (*physics).CreateBodyRectangle(position, spriteController.getSpriteDimentions().x, spriteController.getSpriteDimentions().y, 1);
        physicsBody->freezeOrient = true; // Constrain body rotation to avoid little collision torque amounts
    }

    void handleInput(const float velocity)
    {
        // Horizontal movement input
        int direction = 0;
        if (IsKeyDown(KEY_RIGHT))
            direction++;
        else if (IsKeyDown(KEY_LEFT))
            direction--;

        // Vertical movement input & check if player physics body is grounded
        if (IsKeyDown(KEY_UP) && physicsBody->isGrounded && !jumpPressed)
        {
            physicsBody->velocity.y = -velocity * 1.5;
            spriteController.setTrack(5); // Set idle track
            jumpPressed = true;
            playerState = Jumping;
        }
        else if (IsKeyUp(KEY_UP))
        {
            jumpPressed = false;
        }

        // Apply movement
        physicsBody->velocity.x = direction * velocity;

        // Animator
        spriteController.setDirection(direction);
        if (direction == 0 && playerState != Idle && physicsBody->isGrounded)
        {
            spriteController.setTrack(0); // Set idle track
            playerState = Idle;
        }
        else if (direction != 0 && playerState != Moving && physicsBody->isGrounded)
        {
            spriteController.setTrack(1); // Set moving track
            playerState = Moving;
        }
    }

    void draw()
    {
        int vertices = physicsBody->shape.vertexData.vertexCount;
        spriteController.draw(GetPhysicsShapeVertex(physicsBody, vertices - 1));
    }

private:
};

#endif