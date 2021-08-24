#include <raylib-cpp.hpp>
#include <character/character.hpp>

int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(60);

    Character pietje;
    Character npc;
    npc.setColor(BROWN);
    npc.setPosition({240,240});

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update
        pietje.onUpdate();
        npc.onUpdate();

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        pietje.onDraw();
        npc.onDraw();
        EndDrawing();
    }

    return 0;
}