#include <raylib-cpp.hpp>
#include <player/player.hpp>
#include <projectile/projectileStorage.hpp>

#include <iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HMmmM, OAH");

    Camera2D camera = {0};
    camera.target = {0, 0};
    camera.offset = {(screenWidth / 2.0f) - 20, (screenHeight / 2.0f) - 20};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Player player(&camera);
    Rectangle debree = Rectangle{30, 30, 30, 30};

    ProjectileStorage pStorage;

    raylib::Vector2 offSet, lastMousePosition;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        player.onUpdate();
        pStorage.onUpdate();

        raylib::Vector2 smooth = ((raylib::Vector2)camera.target - player.position) / 2;

        camera.target = (raylib::Vector2)player.position + smooth;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        pStorage.onDraw();
        player.onDraw();
        DrawRectangleRec(debree, RED);

        EndMode2D();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}