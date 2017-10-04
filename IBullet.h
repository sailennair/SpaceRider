#ifndef IBULLET_H
#define IBULLET_H

#include "IMovingGameObject.h"

class IBullet
{
public:
    virtual void moveLeftX() = 0;
    virtual void moveLeftY() = 0;
    virtual void moveRightX() = 0;
    virtual void moveRightY() = 0;
    virtual float getAngleofRotation() = 0;
    virtual bool isAlive() = 0;
    virtual int getXposition() = 0;
    virtual int getYposition() = 0;
    virtual void setDamage(int damage) = 0;
    virtual int getDamage() = 0;
};

#endif // IBULLET_H
