#include <raylib-cpp.hpp>
#include <player/player.hpp>
#include <projectile/projectileStorage.hpp>
#include <camera/smoothCamera.hpp>

#include <iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1250;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Floin'");

    SmoothCamera camera;
    camera.setup(screenWidth, screenHeight);

    Player player(camera.getCamera());

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        player.onUpdate();
        ProjectileStorage().onUpdate();
        camera.followTarget(player.position);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground({0, 4, 23, 255});

        BeginMode2D(*camera.getCamera());

        ProjectileStorage().onDraw();
        player.onDraw();

        EndMode2D();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}