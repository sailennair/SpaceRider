#include "EnemyLogic.h"

EnemyLogic::EnemyLogic(int x, int y, int width, int height, float theta):
    _xPos{x},
    _yPos{y},
    _width{width},
    _height{height},
    _theta{theta},
    _health{100} // Health should always default to 100%
    {
        
    }
    
void EnemyLogic::move(){
    _xPos +=_xPos*cos(_theta)*0.0075;
    _yPos += _yPos*sin(_theta)*0.0075;
    
    _width += 0.25;
    _height += 0.25;
    
    _scale += (((_width + 0.5)/_width) - 1)*0.1;
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
int EnemyLogic::getXPosition(){
    return _xPos;
}
int EnemyLogic::getYPosition(){
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
