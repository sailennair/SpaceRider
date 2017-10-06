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
    //IMovingGameObject(){};
  // virtual void setPosition(int xPosition, int yPosotion) = 0;
//   virtual void moveLeftX() = 0;
//   virtual void moveLeftY() = 0;
//   virtual void moveRightX() = 0;
//   virtual void moveRightY() = 0;
  // virtual void move() = 0;
   virtual float getWidth() = 0;
   virtual float getHeight() = 0;
   //virtual float getAngleofRotation() = 0;
   virtual bool isAlive() = 0;
   virtual float getXposition() =0;
   virtual float getYposition() =0;
   
   // virtual ~IMovingGameObject(){};
};



#endif // IMOVINGGAMEOBJECT_H
