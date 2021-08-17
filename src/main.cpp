/*******************************************************************************************
*
*   Physac - Physics demo
*
*   NOTE 1: Physac requires multi-threading, when InitPhysics() a second thread is created to manage physics calculations.
*   NOTE 2: Physac requires static C library linkage to avoid dependency on MinGW DLL (-static -lpthread)
*
*   Use the following line to compile:
*
*   gcc -o $(NAME_PART).exe $(FILE_NAME) -s -static  /
*       -lraylib -lpthread -lglfw3 -lopengl32 -lgdi32 -lopenal32 -lwinmm /
*       -std=c99 -Wl,--subsystem,windows -Wl,-allow-multiple-definition
*
*   Copyright (c) 2016-2018 Victor Fisac
*
********************************************************************************************/

#include <iostream>
#include "raylib-cpp.hpp"

#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS
#include "Physics.hpp"

#define VELOCITY    0.5f

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    raylib::Window w(screenWidth, screenHeight, "Physac - Body controller demo");
    
    // Physac logo drawing position
    int logoX = screenWidth - MeasureText("Physac", 30) - 10;
    int logoY = 15;

    // Initialize physics and default physics bodies
    raylib::Physics physics;

    // Create floor and walls rectangle physics body
    PhysicsBody floor = physics.CreateBodyRectangle(Vector2{ screenWidth/2, screenHeight }, screenWidth, 100, 10);
    PhysicsBody platformLeft = physics.CreateBodyRectangle(Vector2{ screenWidth*0.25f, screenHeight*0.6f }, screenWidth*0.25f, 10, 10);
    PhysicsBody platformRight = physics.CreateBodyRectangle(Vector2{ screenWidth*0.75f, screenHeight*0.6f }, screenWidth*0.25f, 10, 10);
    PhysicsBody wallLeft = physics.CreateBodyRectangle(Vector2{ -5, screenHeight/2 }, 10, screenHeight, 10);
    PhysicsBody wallRight = physics.CreateBodyRectangle(Vector2{ screenWidth + 5, screenHeight/2 }, 10, screenHeight, 10);

    // Disable dynamics to floor and walls physics bodies
    floor->enabled = false;
    platformLeft->enabled = false;
    platformRight->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;

    // Create movement physics body
    PhysicsBody body = physics.CreateBodyRectangle(Vector2{ screenWidth/2, screenHeight/2 }, 50, 50, 1);
    body->freezeOrient = true;  // Constrain body rotation to avoid little collision torque amounts
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!w.ShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        physics.RunStep();
        
        // Horizontal movement input
        if (IsKeyDown(KEY_RIGHT))
            body->velocity.x = VELOCITY;
        else if (IsKeyDown(KEY_LEFT))
            body->velocity.x = -VELOCITY;

        // Vertical movement input checking if player physics body is grounded
        if (IsKeyDown(KEY_UP) && body->isGrounded)
            body->velocity.y = -VELOCITY*4;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawFPS(screenWidth - 90, screenHeight - 30);
        DrawText("IDLE KING!", screenWidth/2 - 120, 100, 50, LIGHTGRAY);

            // Draw created physics bodies
            int bodiesCount = GetPhysicsBodiesCount();
            for (int i = 0; i < bodiesCount; i++)
            {
                PhysicsBody body = GetPhysicsBody(i);

                int vertexCount = GetPhysicsShapeVerticesCount(i);
                for (int j = 0; j < vertexCount; j++)
                {
                    // Get physics bodies shape vertices to draw lines
                    // Note: GetPhysicsShapeVertex() already calculates rotation transformations
                    Vector2 vertexA = GetPhysicsShapeVertex(body, j);

                    int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);   // Get next vertex or first to close the shape
                    Vector2 vertexB = GetPhysicsShapeVertex(body, jj);

                    DrawLineV(vertexA, vertexB, GREEN);     // Draw a line between two vertex positions
                }
            }

            DrawText("Use 'ARROWS' to move player", 10, 10, 10, WHITE);

            DrawText("Physac", logoX, logoY, 30, WHITE);
            DrawText("Powered by", logoX + 50, logoY - 7, 10, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    ClosePhysics();       // Unitialize physics
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}