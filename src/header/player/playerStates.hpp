#pragma once

class Player;

class PlayerState
{
public:
    virtual void onUpdate(Player &character) = 0;
    virtual void onEntry(Player &character) = 0;
    virtual ~PlayerState();

protected:
    void setState(Player &character, PlayerState *state);
};

// Idle state
//----------------------------------------------------------------------------------
class Idle : public PlayerState
{
public:
    virtual void onUpdate(Player &character);
    virtual void onEntry(Player &character);
    virtual ~Idle();
};

// Moving state
//----------------------------------------------------------------------------------
class Moving : public PlayerState
{
public:
    Moving(Vector2 direction);
    virtual void onUpdate(Player &character);
    virtual void onEntry(Player &character);
    virtual ~Moving();

private:
    int frames = 0;
    Vector2 direction;
};

// Triggered state
//----------------------------------------------------------------------------------
class Triggered : public PlayerState
{
public:
    virtual void onUpdate(Player &character);
    virtual void onEntry(Player &character);
    virtual ~Triggered();
    
private:
    int frames = 0;
};