#ifndef IGAMECHARACTER_H
#define IGAMECHARACTER_H

#include "IMovingGameObject.h"

class IGameCharacter : public IMovingGameObject
{
public:
    // virtual void setPosition(int xPosition, int yPosotion) = 0;

    virtual void moveLeftX() = 0;

    virtual void moveLeftY() = 0;

    virtual void moveRightX() = 0;

    virtual void moveRightY() = 0;

    virtual void setAngleofRotation(int angle) = 0;

    virtual bool isAlive() = 0;

    virtual void reduceHealth(int _damage) = 0;

    virtual int getXposition() = 0;
    
    virtual int getYposition() = 0;
};

#endif // IGAMECHARACTER_H
