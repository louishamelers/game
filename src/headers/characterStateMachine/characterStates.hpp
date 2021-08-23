#pragma once

#include "character.hpp"

class Character;

class AbsCharState
{
public:
    virtual void jumpInput(Character &character, bool jump) = 0;
    virtual void moveInput(Character &character, int direction) = 0;
    virtual ~AbsCharState();

protected:
    void setState(Character &character, AbsCharState *state);
};

class Idle : public AbsCharState
{
public:
    virtual void jumpInput(Character &character, bool jump);
    virtual void moveInput(Character &character, int direction);
    virtual ~Idle();
};