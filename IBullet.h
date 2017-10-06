#ifndef IBULLET_H
#define IBULLET_H

#include "IMovingGameObject.h"

class IBullet : public IMovingGameObject
{
public:
    virtual void move() = 0;

    virtual void setDamage(int damage) = 0;

    virtual int getDamage() = 0;

    virtual bool isAlive() = 0;

    virtual float getXposition() = 0;

    virtual float getYposition() = 0;

    virtual float getWidth() = 0;

    virtual float getHeight() = 0;
    
    virtual void setLife(bool life) = 0 ;
};

#endif // IBULLET_H
