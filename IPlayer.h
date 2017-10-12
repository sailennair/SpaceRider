#ifndef IPLAYER_H
#define IPLAYER_H

#include "IMovingGameObject.h"

class IPlayer: public IMovingGameObject
{
public:
    virtual void moveLeftX() = 0;

    virtual void moveLeftY() = 0;

    virtual void moveRightX() = 0;

    virtual void moveRightY() = 0;

    virtual bool isAlive() = 0;

    virtual float getXposition() = 0;

    virtual float getYposition() = 0;

    virtual void reduceHealth(int _damage) = 0;

    virtual float getTheta() = 0;

    virtual void playerMove(Direction dir) = 0;
    
    virtual float getRadius() = 0;
    
     virtual float getCenterXPosition() = 0;
    
    virtual float getCenterYPosition() = 0;
};

#endif // IPLAYER_H
