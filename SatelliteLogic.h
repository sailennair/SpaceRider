#ifndef SATELLITELOGIC_H
#define SATELLITELOGIC_H
#include <math.h>
#include "IMovingGameObject.h"
#include "EnemyBulletLogic.h"

class SatelliteLogic : public IMovingGameObject
{
public:
    SatelliteLogic(float x, float y, float theta);

    void move();

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
    
    int _radiusOfRotation;
    
  
};

#endif