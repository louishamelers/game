#include <raylib-cpp.hpp>

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1

int main() {
    
    // Initialization
    int screenWidth = 800;
    int screenHeight = 550;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");

    // Player sprite animation
    //--------------------------------------------------------------------------------------
    Texture2D spriteSheet = LoadTexture("src/assets/sprites/myboy.png"); // -> Load textures after window initialization (OpenGL context is required)
    int spriteTrackLengths[] = {13,8,10,10,10,6,4,7};
    int spriteTracks = (sizeof(spriteTrackLengths)/sizeof(spriteTrackLengths[0]));
    int maxSprites = 13;
    int currentTrack = 0;

    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    Rectangle frameRect = {0.0f, 0.0f, (float)spriteSheet.width/maxSprites, (float)spriteSheet.height/spriteTracks};
    Vector2 playerPosition = {screenWidth/2 - frameRect.width/2, 50};
    
    // Sprite demo properties
    //--------------------------------------------------------------------------------------
    Vector2 speedGUIPosition = {0, (float)playerPosition.y + 70};
    Vector2 spriteSheetPosition = {(float)screenWidth/2 - spriteSheet.width/2, speedGUIPosition.y + 70};
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update
        framesCounter++;

        if(framesCounter >= (60/framesSpeed)) {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > spriteTrackLengths[currentTrack]-1) currentFrame = 0;

            frameRect.x = (float)currentFrame*(float)spriteSheet.width/maxSprites;
            frameRect.y = (float)currentTrack*(float)spriteSheet.height/spriteTracks;
        }

        if (IsKeyPressed(KEY_RIGHT)) framesSpeed++;
        else if (IsKeyPressed(KEY_LEFT)) framesSpeed--;

        if (framesSpeed > MAX_FRAME_SPEED) framesSpeed = MAX_FRAME_SPEED;
        else if (framesSpeed < MIN_FRAME_SPEED) framesSpeed = MIN_FRAME_SPEED;

        if (IsKeyPressed(KEY_DOWN)) currentTrack++;
        else if (IsKeyPressed(KEY_UP)) currentTrack--;

        if (currentTrack > spriteTracks-1) currentTrack = 0;
        else if (currentTrack < 0) currentTrack = spriteTracks-1;
        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureRec(spriteSheet, frameRect, playerPosition, WHITE);  // Draw part of the texture

        // Character demo stuff
        DrawTexture(spriteSheet, spriteSheetPosition.x, spriteSheetPosition.y, WHITE);
        DrawRectangleLines(spriteSheetPosition.x + (int)frameRect.x, spriteSheetPosition.y + (int)frameRect.y, (int)frameRect.width, (int)frameRect.height, RED);

        // Speed thing
        DrawText("FRAME SPEED: ", 165, speedGUIPosition.y, 10, DARKGRAY);
        DrawText(TextFormat("%02i FPS", framesSpeed), 575, speedGUIPosition.y, 10, DARKGRAY);
        DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, speedGUIPosition.y+30, 10, DARKGRAY);

        for (int i = 0; i < MAX_FRAME_SPEED; i++)
        {
            if (i < framesSpeed) DrawRectangle(250 + 21*i, speedGUIPosition.y - 5, 20, 20, RED);
            DrawRectangleLines(250 + 21*i, speedGUIPosition.y - 5, 20, 20, MAROON);
        }

        // Extra text
        DrawText("(c) Waldo, the IDLE king!", screenWidth - 170, screenHeight - 20, 10, GRAY);

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(spriteSheet);       // Texture unloading

    return 0;
}