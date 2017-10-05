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
  // virtual void setPosition(int xPosition, int yPosotion) = 0;
    virtual void move() = 0;
    virtual void setAngleofRotation(int angle) = 0;
    virtual bool isAlive() = 0;
    virtual int getXposition() =0;
    virtual int getYposition() =0;
   

};



#endif // IMOVINGGAMEOBJECT_H
