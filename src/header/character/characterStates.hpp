#pragma once

class Character;

class AbsCharState
{
public:
    virtual void onUpdate(Character &character) = 0;
    virtual void onEntry(Character &character) = 0;
    virtual ~AbsCharState();

protected:
    void setState(Character &character, AbsCharState *state);
};

// Idle state
//----------------------------------------------------------------------------------
class Idle : public AbsCharState
{
public:
    virtual void onUpdate(Character &character);
    virtual void onEntry(Character &character);
    virtual ~Idle();
};

// Moving state
//----------------------------------------------------------------------------------
class Moving : public AbsCharState
{
public:
    Moving(Vector2 direction);
    virtual void onUpdate(Character &character);
    virtual void onEntry(Character &character);
    virtual ~Moving();

private:
    int frames = 0;
    Vector2 direction;
};

// Triggered state
//----------------------------------------------------------------------------------
class Triggered : public AbsCharState
{
public:
    virtual void onUpdate(Character &character);
    virtual void onEntry(Character &character);
    virtual ~Triggered();
    
private:
    int frames = 0;
};