#pragma once
#include <raylib-cpp.hpp>
#include <Vector2.hpp>
#include <util/entity.hpp>

class SmoothCamera : public Entity
{
public:
    SmoothCamera();
    ~SmoothCamera();
    void onUpdate();
    void onDraw();
    void setup(int screenWidth, int screenHeight);
    void setTarget(Vector2 *targetPosition);
    Camera2D* getCamera();

private:
    Camera2D camera;
    int smoothness = 2;
    Vector2* target;
};
