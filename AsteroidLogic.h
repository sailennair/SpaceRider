#ifndef ASTEROIDLOGIC_H
#define ASTEROIDLOGIC_H

#include "GameCommonData.h"
#include "math.h"
#include <iostream>
#include "IEnemy.h"

class AsteroidLogic : public IEnemy
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

    float getRadius();

    float getCenterXPosition();

    float getCenterYPosition();

    void setOutOfBounds(bool bounds);

    bool isOutOfBounds();

    float getDamage();

private:
    float _xpos;
    float _ypos;
    float _theta;
    bool _isAlive = true;
    int _health = 10000;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.005;
    bool _outOfBounds = false;
    float _centerXPosition;
    float _centerYPosition;
    float _radius;
    float _damage = 20;
    int asteroidSize = 20;
};

#endif // ASTEROIDLOGIC_H
