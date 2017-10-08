#include "SatelliteLogic.h" 
//10 degrees  = 0.0175 rads 
SatelliteLogic::SatelliteLogic(float x, float y, float theta): 
    _xPos{x}, 
    _yPos{y}, 
    _spawnedXpos{x}, 
    _spawnedYpos{y}, 
    _angleOfRotation{theta}, 
    _health{100}    // Health should always be inititalized to 100% 
    { 
     
    } 
     
void SatelliteLogic::move(){ 
    // chosing a new point to rotate about 
    auto xPoint = _spawnedXpos + 10; 
    auto yPoint = _spawnedYpos + 10; 
     
    float s = sin(_angleOfRotation);  
    float c = cos(_angleOfRotation); 
     
    // translating the position to a rotation origen 
    auto translatedX = _xPos - xPoint; 
    auto translatedY = _yPos - yPoint; 
     
    //rotation about origin 
    auto newXpos = translatedX*c - translatedY*s; 
    auto newYpos = translatedX*s + translatedY*c; 
     
    // translate the point back to a rotation about xPoint YPoint 
    _xPos = newXpos + xPoint; 
    _yPos = newYpos + yPoint; 
} 
 
// Getter functions 
float SatelliteLogic::getWidth(){ 
    return _xPos + 20; 
} 
float SatelliteLogic::getHeight(){ 
    return _yPos + 20; 
} 
float SatelliteLogic::getXposition(){ 
    return _xPos; 
} 
float SatelliteLogic::getYposition(){ 
    return _yPos; 
} 
 
 
bool SatelliteLogic::isAlive(){ 
    if(_health>0) 
        return true; 
    return false; 
} 
 
void SatelliteLogic::decreaseHealth(int damage){ 
    _health -= damage; 
}

float SatelliteLogic::getRadius(){
    return _radius;
}


float SatelliteLogic::getCenterXPosition(){
    return _centerXPosition;
    
}

float SatelliteLogic::getCenterYPosition(){
    return _centerYPosition;
    
}
