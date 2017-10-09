#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include <iostream>
#include <math.h>
#include "IPlayer.h"
#include <memory>

class PlayerLogic : public IPlayer
{
public:
    PlayerLogic();

    // void setPosition(int xPosition, int yPosotion);

    void moveLeftX();

    void moveLeftY();

    void moveRightX();

    void moveRightY();

    float getAngleofRotation();

    bool isAlive();

    void reduceHealth(int _damage);

    float getXposition();

    float getYposition();

    float getTheta();

    float degreesToRadians(float x);

    void playerMove(Direction dir);

    float getWidth();

    float getHeight();

    float getRadius();
    
    float getCenterXPosition();
    
    float getCenterYPosition();
    
    int getHealth();
    
    bool setLife(bool life);

private:
bool _life = true;
    int _health;
    float _theta =  (PI) / 2;
    int _xpos;
    int _ypos;
    float _angleOfRotation;
    float _width;
    float _height;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
};

#endif // PLAYERLOGIC_H
