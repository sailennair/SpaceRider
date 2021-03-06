#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include <iostream>
#include <math.h>
#include "IGameCharacter.h"

class PlayerLogic : public IGameCharacter
{
public:
    PlayerLogic();

   // void setPosition(int xPosition, int yPosotion);

    void moveLeftX();

    void moveLeftY();

    void moveRightX();

    void moveRightY();

    void setAngleofRotation(int angle);

    bool isAlive();

    void reduceHealth(int _damage);

    int getXposition();
    
    int getYposition();
    
    float getTheta(); 
    
    float degreesToRadians(float x);
    
    void playerMove(Direction dir);

private:
    int _health;
    float _theta = (PI) / 2;
    int _xpos;
    int _ypos;
    int _angleOfRotation;
};

#endif // PLAYERLOGIC_H
