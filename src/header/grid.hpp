#pragma once

#include <entity/entity.hpp>

class Grid : public Entity
{
private:
    /* data */
public:
    Grid();
    ~Grid();
    void onUpdate();
    void onDraw();

    int width, height;
};