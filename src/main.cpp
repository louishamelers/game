#include <raylib-cpp.hpp>

#define MAX_BUILDINGS 100

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "HMmmM, OAH");

    Rectangle player = {0, 0, 40, 40};

    Camera2D camera = {0};
    camera.target = {0,0};
    camera.offset = {(screenWidth / 2.0f) - 20, (screenHeight / 2.0f) - 20};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    raylib::Vector2 offSet, lastMousePosition;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            lastMousePosition = GetMousePosition();
        else if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            offSet = ((raylib::Vector2)GetMousePosition() - lastMousePosition);
            lastMousePosition = GetMousePosition();
            camera.target = (raylib::Vector2)camera.target += (offSet * -1);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        DrawRectangleRec(player, RED);

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