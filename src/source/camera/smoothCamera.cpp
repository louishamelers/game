#include <camera/smoothCamera.hpp>

SmoothCamera::SmoothCamera()
{
    camera = {0};
}

SmoothCamera::~SmoothCamera()
{
}

void SmoothCamera::setup(int screenWidth, int screenHeight)
{
    camera.target = {0, 0};
    camera.offset = {(screenWidth / 2.0f) - 20, (screenHeight / 2.0f) - 20};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void SmoothCamera::followTarget(Vector2 targetPosition)
{
    raylib::Vector2 smooth = ((raylib::Vector2)camera.target - targetPosition) / 2;
    camera.target = (raylib::Vector2)targetPosition + smooth;
}

Camera2D *SmoothCamera::getCamera()
{
    return &camera;
}