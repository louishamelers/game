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

class Player
{
public:
    PhysicsBody physicsBody;
    SpriteController spriteController;
    Vector2 position{0, 0};
    int lookingDirection = 0;
    int playerState = 0;
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
        int direction = 0;

        // Horizontal movement input
        if (IsKeyDown(KEY_RIGHT))
        {
            physicsBody->velocity.x = velocity;
            direction = 1;
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            physicsBody->velocity.x = -velocity;
            direction = -1;
        }

        // Vertical movement input checking if player physics body is grounded
        if (IsKeyDown(KEY_UP) && physicsBody->isGrounded && !jumpPressed)
        {
            physicsBody->velocity.y = -velocity * 6;
            jumpPressed = true;
        } else if(IsKeyUp(KEY_UP)) {
            jumpPressed = false;
        }

        // Animator state
        if (direction == 0 && playerState == 1)
        {
            playerState = 0;
            spriteController.setTrack(0); //idle track
        }
        else if (direction != 0 && playerState != 1)
        {
            playerState = 1;
            spriteController.setTrack(1); //running track
        }

        this->lookingDirection = direction;
        spriteController.setDirection(this->lookingDirection);
    }

    void draw()
    {
        std::cout << GetPhysicsShapeVertex(physicsBody, 0).x << std::endl;
        // Vector2 spritePosition = {
        //     physicsBody->position.x - physicsBody->shape.vertexData
        // };
        int vertices = physicsBody->shape.vertexData.vertexCount;
        spriteController.draw(GetPhysicsShapeVertex(physicsBody, vertices - 1));
    }

private:
};

#endif