#include "EnemyLogic.h"
#include "GameCommonData.h"
#include  <iostream>
EnemyLogic::EnemyLogic(float x, float y, float width, float height, float theta):
    _xPos{x},
    _yPos{y},
    _width{width},
    _height{height},
    _originalWidth{width},
    _originalHeight{height},
    _theta{theta},
    _health{100}, // Health should always default to 100%
    _scale{0.03},
    _originalScale{0.03}
    {
        deltaX = _xPos;
        deltaY = _yPos;
        
    }
    
void EnemyLogic::move(){
    auto Origin = 400 - _xPos;
    _xPos += deltaX*cos(_theta)*0.0007;
    _yPos += deltaY*cos(_theta)*0.0007;
    
    auto currentRadius = sqrt(pow(_xPos - centerOfScreenX,2) + pow(_yPos - centerOfScreenY, 2));
    auto percentageChange = currentRadius/radius;
    
//    _width += 0.25*percentageChange;
//    _height += 0.25*percentageChange;
    _width += 0.5*percentageChange;
    _height += 0.5*percentageChange;
    std::cout << _width << " " << _height << std::endl;
    
    _scale = percentageChange;
    //_scale += (((_width + 0.5)/_width) - 1)*0.05;
}

void EnemyLogic::moveToCenter(float x, float y, float theta){
    _width = _originalWidth;
    _height = _originalHeight;
    _scale = _originalScale;
    _xPos = x;
    _yPos = y;
    _theta = theta;
}

void EnemyLogic::decreaseHealth(int damage){
    _health -= damage;
}
bool EnemyLogic::isAlive(){
    if(_health > 0){
        return true;
    }
    return false;
}
void EnemyLogic::reSize(int changeInWidth, int changeInHeight){
    _width += changeInWidth;
    _height += changeInHeight;
}

// ************GETTERS*****************   
float EnemyLogic::getXPosition(){
    return _xPos;
}
float EnemyLogic::getYPosition(){
    return _yPos;
} 
int EnemyLogic::getCenterX(){
    int centreX = _xPos + (_width/ 2);
    return centreX;
}
int EnemyLogic::getCenterY(){
    int centreY = _yPos + (_height/ 2);
    return centreY;
}
int EnemyLogic::getTheta(){
    return _theta;
}    
int EnemyLogic::getHealth(){
    return _health;
}
float EnemyLogic::getScale(){
    return _scale;
}
float EnemyLogic::getWidth(){
    return _width;
}
float EnemyLogic::getHeight(){
    return _height;
}