#ifndef IMOVINGGAMEOBJECT_H
#define IMOVINGGAMEOBJECT_H

#include <vector>
#include <map>
#include <utility>
#include "GameCommonData.h"

#define PI 3.14159265

using namespace std;

class IMovingGameObject
{
public:
    
    virtual bool isAlive() = 0;
    
    virtual float getXposition() = 0;

    virtual float getYposition() = 0;

    virtual float getRadius() = 0;
    
    virtual float getCenterXPosition() = 0;
    
    virtual float getCenterYPosition() = 0;

};

#endif // IMOVINGGAMEOBJECT_H
