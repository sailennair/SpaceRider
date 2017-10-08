#ifndef SATELLITELOGIC_H
#define SATELLITELOGIC_H
#include <math.h>
#include "IMovingGameObject.h"

class SatelliteLogic : private IMovingGameObject
{
public:
    SatelliteLogic(float x, float y, float theta);

    void move();

    // Getter functions
    float getWidth();
    
    float getHeight();
    
    float getXposition();
    
    float getYposition();

    bool isAlive();

    void decreaseHealth(int damage);

    float getRadius();

    float getCenterXPosition();

    float getCenterYPosition();

private:
    float _xPos;
    
    float _yPos;

    float _spawnedXpos;
    
    float _spawnedYpos;

    float _angleOfRotation; // This will essentially be the speed of rotation

    int _health;
    
    float _radius;
    
    float _centerXPosition;
    
    float _centerYPosition;
};

#endif