#pragma once
#include <raylib-cpp.hpp>
#include <Vector2.hpp>

class SmoothCamera
{
public:
    SmoothCamera();
    ~SmoothCamera();
    void setup(int screenWidth, int screenHeight);
    void setTarget(Vector2 *targetPosition);
    void onUpdate();
    Camera2D* getCamera();

private:
    Camera2D camera;
    int smoothness = 2;
    Vector2* target;
};
