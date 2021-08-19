#ifndef SPRITE_H
#define SPRITE_H
#include <iostream>
#include <vector>
#include <raylib-cpp.hpp>

class SpriteController
{
public:
    SpriteController();
    SpriteController(Texture2D spriteSheet,
                     std::vector<int> tracks);
    void update();
    void draw(Vector2 location);

    void setTrack(int track);
    void setDirection(int direction);
    Rectangle getSpriteFrame();
    Vector2 getSpriteDimentions();

    ~SpriteController();

protected:
    Texture2D sprite;
    std::vector<int> tracks;
    
    int maxSprites = 0;
    int currentTrack = 0;
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;
    int scale = 1;

    Rectangle frameRec;
    
private:
};

#endif // SPRITE_H