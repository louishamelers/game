#include <raylib-cpp.hpp>
#include <player.hpp>
#include <smoothCamera.hpp>
#include <entity/entityStorage.hpp>
#include <starMap.hpp>

#include <iostream>

void update();
void draw();

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1250;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "IDLE SPACE");

    SmoothCamera camera;
    camera.setup(screenWidth, screenHeight);

    Player player(camera.getCamera());
    camera.setTarget(&player.position);

    StarMap starMap(camera.getCamera(), screenWidth, screenHeight);

    EntityStorage().add(&camera);
    EntityStorage().add(&player);

    Rectangle rec{20, 20, 20, 20};

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        EntityStorage().updateEntities();
        starMap.onUpdate();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground({0, 4, 23, 255});

        DrawFPS(screenWidth - 90, screenHeight - 30);

        starMap.onDraw();

        BeginMode2D(*camera.getCamera());

        DrawRectangleRec(rec, RED);
        EntityStorage().drawEntities();

        EndMode2D();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}