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

#define PHYSAC_IMPLEMENTATION
#define PHYSAC_NO_THREADS

#include <vector>
#include <iostream>
#include <raylib-cpp.hpp>
#include <Physics.hpp>
#include "headers/Player.hpp"
#include "headers/characterStateMachine/machineStates.hpp"
#include "headers/characterStateMachine/machine.hpp"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    raylib::Window w(screenWidth, screenHeight, "Physac - Body controller demo");

    // Initialize physics and default physics bodies
    raylib::Physics physics;

    physics.SetGravity(0,1.5);

    // Create floor and walls rectangle physics body
    PhysicsBody floor = physics.CreateBodyRectangle(Vector2{screenWidth / 2, screenHeight}, screenWidth, 100, 10);
    PhysicsBody platformLeft = physics.CreateBodyRectangle(Vector2{screenWidth * 0.25f, screenHeight * 0.8f}, screenWidth * 0.25f, 10, 10);
    PhysicsBody platformRight = physics.CreateBodyRectangle(Vector2{screenWidth * 0.75f, screenHeight * 0.6f}, screenWidth * 0.25f, 10, 10);
    PhysicsBody wallLeft = physics.CreateBodyRectangle(Vector2{-6, screenHeight / 2}, 10, screenHeight, 10);
    PhysicsBody wallRight = physics.CreateBodyRectangle(Vector2{screenWidth + 5, screenHeight / 2}, 10, screenHeight, 10);

    // Disable dynamics to floor and walls physics bodies
    floor->enabled = false;
    platformLeft->enabled = false;
    platformRight->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;

    Player player(&physics);
    player.physicsBody->position = {screenWidth / 2, screenHeight / 2};

    // ----------------------------------------------------------------------------------------------------------------------------- TRASH

    std::cout << "STATE MACHINE DEMO!" << std::endl;
    Machine m1(10);
    std::cout << m1.getStock() << std::endl;
    m1.sell(5);
    std::cout << m1.getStock() << std::endl;
    m1.sell(5);
    std::cout << m1.getStock() << std::endl;

    // ---------------------------------------------------------------------------------------------------------------------------- /TRASH

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        physics.RunStep();


        player.handleInput(0.2f);
        player.spriteController.update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("IDLE KING!", screenWidth / 2 - 120, 100, 50, LIGHTGRAY);

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

                int jj = (((j + 1) < vertexCount) ? (j + 1) : 0); // Get next vertex or first to close the shape
                Vector2 vertexB = GetPhysicsShapeVertex(body, jj);

                DrawLineV(vertexA, vertexB, GREEN); // Draw a line between two vertex positions
            }
        }
        player.draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    ClosePhysics(); // Unitialize physics

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}