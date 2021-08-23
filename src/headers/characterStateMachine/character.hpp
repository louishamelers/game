#pragma once

class AbsCharState;

class Character
{
    friend class AbsCharState;

public:
    Character();
    void movementInput(int direction);
    void jumpInput(bool jump);
    ~Character();

private:
    AbsCharState *state;
};