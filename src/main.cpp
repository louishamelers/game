#include <raylib-cpp.hpp>
#include <player/player.hpp>
#include <projectile/projectileStorage.hpp>
#include <camera/smoothCamera.hpp>
#include <util/entityStorage.hpp>

#include <iostream>

void update();
void draw();
SmoothCamera camera;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1250;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Floin'");

    camera.setup(screenWidth, screenHeight);

    Player player(camera.getCamera());
    camera.setTarget(&player.position);
    EntityStorage().add(&player);

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        update();
        camera.onUpdate();

        // Draw
        //----------------------------------------------------------------------------------
        draw();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}

void update()
{
    ProjectileStorage().onUpdate();
    for (Entity *entity : *EntityStorage().getEntities())
        entity->onUpdate();
}

void draw()
{
    BeginDrawing();

    ClearBackground({0, 4, 23, 255});

    BeginMode2D(*camera.getCamera());

    ProjectileStorage().onDraw();
    for (Entity *entity : *EntityStorage().getEntities())
        entity->onDraw();

    EndMode2D();

    EndDrawing();
}