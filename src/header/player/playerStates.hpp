#pragma once

class Player;

class PlayerState
{
public:
    virtual void shoot(Player &player) = 0;
    virtual void onEntry(Player &player) = 0;
    virtual ~PlayerState();

protected:
    void setState(Player &player, PlayerState *state);
};

// Idle state
//----------------------------------------------------------------------------------
class Healthy : public PlayerState
{
public:
    virtual void shoot(Player &player);
    virtual void onEntry(Player &player);
    virtual ~Healthy();
};

// // Moving state
// //----------------------------------------------------------------------------------
// class Moving : public PlayerState
// {
// public:
//     Moving(Vector2 direction);
//     virtual void onUpdate(Player &player);
//     virtual void onEntry(Player &player);
//     virtual ~Moving();

// private:
//     int frames = 0;
//     Vector2 direction;
// };

// // Triggered state
// //----------------------------------------------------------------------------------
// class Triggered : public PlayerState
// {
// public:
//     virtual void onUpdate(Player &player);
//     virtual void onEntry(Player &player);
//     virtual ~Triggered();
    
// private:
//     int frames = 0;
// };