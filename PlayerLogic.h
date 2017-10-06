#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include <iostream>
#include <math.h>
#include "IGameCharacter.h"
#include <memory>

class PlayerLogic : public IMovingGameObject
{
public:
    PlayerLogic();

   // void setPosition(int xPosition, int yPosotion);

    void moveLeftX();

    void moveLeftY();

    void moveRightX();

    void moveRightY();

    float getAngleofRotation();

    virtual bool isAlive() override;

    void reduceHealth(int _damage);

    virtual float getXposition() override;
    
    virtual float getYposition() override;
    virtual float getWidth() override;
    virtual float getHeight() override;
    
    float getTheta(); 
    
    float degreesToRadians(float x);
    
    void playerMove(Direction dir);

private:
    int _health;
    float _theta = (PI) / 2;
    int _xpos;
    int _ypos;
    float _angleOfRotation;
};

#endif // PLAYERLOGIC_H
