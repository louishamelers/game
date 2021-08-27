#include <projectile/projectile.hpp>
#include <raylib-cpp.hpp>


Projectile::Projectile(Vector2 startPosition, float direction, Entity *origin, int speed)
{
    position = startPosition;
    this->direction = direction;
    this->speed = speed;
}

Projectile::~Projectile()
{
}

void Projectile::onUpdate() {
    float new_x = position.x + speed * cos(direction * PI / 180);
    float new_y = position.y + speed * sin(direction * PI / 180);
    position.x = new_x;
    position.y = new_y;
}

void Projectile::onDraw() {
    Rectangle lekker{position.x, position.y, 10, 10};
    DrawRectangleRec(lekker, BLACK);
}