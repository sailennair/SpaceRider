#ifndef IENEMY_H
#define IENEMY_H

#include "IMovingGameObject.h"
class IEnemy : public IMovingGameObject
{
public:
    virtual void move() = 0;

    virtual float getAngleofRotation() = 0;

    virtual bool isAlive() = 0;

    virtual void reduceHealth(int _damage) = 0;

    virtual float getXposition() = 0;

    virtual float getYposition() = 0;

    virtual void setLife(bool life) = 0;

    virtual float getWidth() = 0;

    virtual float getHeight() = 0;
};

#endif // IENEMY_H
