#include <player/player.hpp>
#include <player/playerStates.hpp>
#include <raylib-cpp.hpp>

#include <iostream>

Player::Player()
{
    state = static_cast<PlayerState *>(new Healthy());
    state->onEntry(*this);
    spaceship = LoadTexture("assets/player.png");
}

Player::~Player() { delete state; }

void Player::onUpdate()
{
    rotateToCursor();
    handleInput();
    doMovement();
    for (auto& projectile: bullets) projectile.onUpdate();
}

void Player::onDraw()
{
    for (auto& projectile: bullets) projectile.onDraw();
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
}

void Player::handleInput()
{
    // Acceleration
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && acceleration <= maxSpeed) acceleration++;
    else if (IsMouseButtonUp(MOUSE_RIGHT_BUTTON)) acceleration /= 1.5;
    // Shooting
    // if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) state->shoot(*this);
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) shoota();
}

void Player::shoota() {
    Projectile bullet(position, rotation, this, 4);
    bullets.push_back(bullet);
}