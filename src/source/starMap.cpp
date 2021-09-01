#include <starMap.hpp>
#include <iostream>
#include <random>
#include <Vector2.hpp>

StarMap::StarMap(Camera2D *camera, int screenWidth, int screenHeight)
{
    this->camera = camera;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->lastCameraPosition = camera->target;
    addStars({camera->offset.x * -1, camera->offset.y * -1, camera->offset.x * 2, camera->offset.y * 2});
}

StarMap::~StarMap()
{
}

void StarMap::onUpdate()
{
    
}

void StarMap::onDraw()
{
    for (Star star : stars)
    {
        Vector2 pos = {
            star.position.x + camera->offset.x - camera->target.x / distance,
            star.position.y + camera->offset.y - camera->target.y / distance};
        DrawCircle(pos.x, pos.y, 65, {255, 255, 255, 1});
        DrawCircle(pos.x, pos.y, 2, {255, 255, 255, (unsigned char)star.brightness});
    }
}

bool StarMap::isDead() { return false; }

void StarMap::addStars(Rectangle area)
{
    const int range_from = 0;
    const int range_to = area.width;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr_x(range_from, range_to);
    std::uniform_int_distribution<int> distr_y(range_from, area.height);
    std::uniform_int_distribution<int> distr_brightness(125, 255);

    for (size_t i = 0; i < (area.width * area.height) / reverseDensity; i++)
    {
        Star star{
            {distr_x(generator) + area.x, distr_y(generator) + area.y},
            distr_brightness(generator)
        };
        stars.push_back(star);
    }
}