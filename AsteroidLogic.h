#ifndef ASTEROIDLOGIC_H
#define ASTEROIDLOGIC_H


#include "GameCommonData.h"
#include "math.h"
#include <iostream>
#include "IEnemy.h"


class AsteroidLogic: public IEnemy
{
public:
    AsteroidLogic(float theta);
    
     void move();

     float getAngleofRotation();

     bool isAlive();

     void reduceHealth(int _damage);

     float getXposition();

     float getYposition();

     void setLife(bool life);

     float getWidth();

     float getHeight();

     float getRadius();

     float getCenterXPosition();

     float getCenterYPosition();
private:

    float _theta;
    float _xpos;
    float _ypos;
    bool _isAlive = true;
    int _health = 10000;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.005;
    bool _outOfBounds = false;
    float _width;
    float _height;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
    
   
};

#endif // ASTEROIDLOGIC_H
