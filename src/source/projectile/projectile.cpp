#include <projectile/projectile.hpp>
#include <raylib-cpp.hpp>


Projectile::Projectile(Vector2 startPosition, float direction, Entity *origin, int speed, int power)
{
    position = startPosition;
    this->direction = direction;
    this->speed = speed;
    this->power = power;
}

Projectile::~Projectile()
{
}

void Projectile::onUpdate() {
    float new_x = position.x + speed * cos(direction * PI / 180);
    float new_y = position.y + speed * sin(direction * PI / 180);
    position.x = new_x;
    position.y = new_y;
    power--;
}

void Projectile::onDraw() {
    DrawCircle(position.x, position.y, power, ORANGE);
    DrawCircle(position.x, position.y, power-2, YELLOW);
}