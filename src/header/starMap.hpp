#pragma once
#include <vector>
#include <Vector2.hpp>
#include <raylib-cpp.hpp>
#include <entity/entity.hpp>

struct Star
{
    Vector2 position;
    int brightness;
};


class StarMap : public Entity
{
public:
    StarMap(Camera2D *camera, int screenWidth, int screenHeight);
    ~StarMap();
    void onUpdate();
    void onDraw();
    bool isDead();

private:
    void addStars(Rectangle area);

    std::vector<Star> stars;
    Camera2D* camera;
    Vector2 lastCameraPosition;
    int distance = 20;
    int reverseDensity = 10000 / 2;
    int screenWidth;
    int screenHeight;
};
