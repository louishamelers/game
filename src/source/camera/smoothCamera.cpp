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

void SmoothCamera::onUpdate() {
    raylib::Vector2 smooth = ((raylib::Vector2)camera.target - *target) / 2;
    camera.target = (raylib::Vector2)*target + smooth;
}

void SmoothCamera::setTarget(Vector2 *targetPosition)
{
    target = targetPosition;
}

Camera2D *SmoothCamera::getCamera()
{
    return &camera;
}