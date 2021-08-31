#include <player/player.hpp>
#include <raylib-cpp.hpp>
#include <projectile/projectileStorage.hpp>

#include <iostream>

Player::Player(Camera2D *camera)
{
    spaceship = LoadTexture("assets/player.png");
    this->camera = camera;
}

Player::~Player() { }

void Player::onUpdate()
{
    rotateToCursor();
    handleInput();
    doMovement();
}

void Player::onDraw()
{
    int frameWidth = spaceship.width;
    int frameHeight = spaceship.height;
    Rectangle sourceRect = {0, 0, frameWidth, frameHeight};
    Rectangle destRect = {position.x, position.y, 84, 84};
    Vector2 origin = {destRect.width / 2, destRect.height / 2};
    DrawTexturePro(spaceship, sourceRect, destRect, origin, rotation + 90, WHITE);
}

void Player::rotateToCursor()
{
    float delta_x = GetMousePosition().x - GetWorldToScreen2D(position, *camera).x;
    float delta_y = GetMousePosition().y - GetWorldToScreen2D(position, *camera).y;
    float cursorAngle = (atan2(delta_y, delta_x) * 180 / PI);
    rotation = cursorAngle;
}

void Player::doMovement() {
    float new_x = position.x + acceleration * cos(rotation * PI / 180);
    float new_y = position.y + acceleration * sin(rotation * PI / 180);
    position.x = new_x;
    position.y = new_y;
    
    if (acceleration != 0) ProjectileStorage().add(new ExhaustParticle(position, rotation-180, this));
}

void Player::handleInput()
{
    // Acceleration
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && acceleration <= maxSpeed) acceleration++;
    else if (IsMouseButtonUp(MOUSE_RIGHT_BUTTON)) acceleration /= 1.5;
    // Shooting
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) shoot();
}

void Player::shoot() {
    if (shootRecoilTime <= 0) {
    ProjectileStorage().add(new Bullet(position, rotation, this));
    shootRecoilTime = fireSpeed;
    } else {
        shootRecoilTime--;
    }
}