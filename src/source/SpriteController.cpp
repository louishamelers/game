#include "../headers/SpriteController.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

SpriteController::SpriteController() {}

SpriteController::SpriteController(Texture2D sprite,
                                   std::vector<int> tracks)
{
    this->sprite = sprite;
    this->tracks = tracks;
    this->maxSprites = *std::max_element(tracks.begin(), tracks.end());
    this->frameRec = {0.0f, 0.0f, ((float)sprite.width / maxSprites) * scale, (float)sprite.height / (tracks.size())};
}

void SpriteController::update()
{
    framesCounter++;

    if (framesCounter >= framesSpeed)
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > tracks[currentTrack] - 1) currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)sprite.width / maxSprites;
        frameRec.y = (float)currentTrack * (float)sprite.height / tracks.size();
        frameRec.width = ((float)sprite.width / maxSprites) * scale;
    }
}

void SpriteController::draw(Vector2 location)
{
    DrawTextureRec(sprite, frameRec, location, WHITE);
}

void SpriteController::setTrack(int track, bool once)
{    
    if (track < 0)
        currentTrack = 0;
    else if ((size_t)track >= tracks.size())
        currentTrack = tracks.size() - 1;
    else
        currentTrack = track;

    currentFrame = 0;
    framesCounter = framesSpeed + 1;
}

void SpriteController::setDirection(int direction) {
    if (direction != 0) this->scale = direction;
}

Rectangle SpriteController::getSpriteFrame()
{
    return frameRec;
}

Vector2 SpriteController::getSpriteDimentions() {
    return {frameRec.width, frameRec.height};
}

SpriteController::~SpriteController()
{
    // UnloadTexture(this->sprite);
}