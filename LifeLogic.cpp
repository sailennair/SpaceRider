#include "LifeLogic.h"


LifeLogic::LifeLogic(){}

LifeLogic::LifeLogic(float x, float y):
    _xpos {x},
    _ypos {y}

{

}

float LifeLogic::getXpos() const
{
    return _xpos;
}

float LifeLogic::getYpos() const
{
    return _ypos;
}

void LifeLogic::setPosition(float x, float y)
{
    _xpos = x;
    _ypos = y;
}

int LifeLogic::getNumberOfLivesRemaining(int health)
{
    if(health > 80 && health <= 100)
        return 5;
    if(health > 60 && health <= 80)
        return 4;
    if(health > 40 && health <= 60)
        return 3;
    if(health > 20 && health <= 40)
        return 2;
    if(health > 0 && health <= 20)
        return 1;
    return 0;
}