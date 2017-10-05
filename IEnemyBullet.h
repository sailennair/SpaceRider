#ifndef IENEMYBULLET_H
#define IENEMYBULLET_H


#include <vector>
#include <map>
#include <utility>
#include "GameCommonData.h"
#include "math.h"

class IEnemyBullet
{
public:
    virtual void move() = 0;

    virtual float getXposition() = 0;

    virtual float getYposition() = 0;

    virtual bool isAlive() = 0;
    
    virtual void setDamage(int damage) = 0;
    
    virtual int getDamage() = 0;
};

#endif // IENEMYBULLET_H
