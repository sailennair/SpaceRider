#ifndef SATELLITELOGIC_H
#define SATELLITELOGIC_H
#include <math.h>
#include "IMovingGameObject.h"

class SatelliteLogic:private IMovingGameObject{
public:
    SatelliteLogic(float x, float y, float theta);
    
    void move();
    
    //Getter functions
    virtual float getWidth()override;
    virtual float getHeight()override;
    virtual float getXposition()override;
    virtual float getYposition()override;
    
    virtual bool isAlive()override;
    
    void decreaseHealth(int damage);
    
private:
    float _xPos;
    float _yPos;
    
    float _spawnedXpos;
    float _spawnedYpos;
    
    float _angleOfRotation; // This will essentially be the speed of rotation

    int _health;
};

#endif
