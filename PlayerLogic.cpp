#include "PlayerLogic.h"

using namespace std;
PlayerLogic::PlayerLogic()
{
    _xpos = PlayerXPosition;
    _ypos = PlayerYPosition;
    _health = PlayerHealth;
}

void PlayerLogic::moveLeftX()
{
    _theta = _theta + degreesToRadians(2);
    _xpos = (radius)*cos(_theta);
    _xpos += xOrigin;
}

void PlayerLogic::moveLeftY()
{
    _theta = _theta + degreesToRadians(2);
    _ypos = (radius)*sin(_theta);
    _ypos += yOrigin;
}

void PlayerLogic::moveRightX()
{
    _theta = _theta + degreesToRadians(-2);
    _xpos = (radius)*cos(_theta);
    _xpos += xOrigin;
    // std::cout<<_theta<<std::endl;
}

void PlayerLogic::moveRightY()
{
    _theta = _theta + degreesToRadians(-2);
    _ypos = (radius)*sin(_theta);
    _ypos += yOrigin;
}

float PlayerLogic::getAngleofRotation()
{

   return _angleOfRotation;
}

bool PlayerLogic::isAlive()
{
    if(_health > 0) {
        return true;
    } else {
        return false;
    }
}

void PlayerLogic::reduceHealth(int _damage)
{
    _health -= _damage;
}

float PlayerLogic::getXposition()
{
    return _xpos;
}

float PlayerLogic::getYposition()
{
    return _ypos;
}

float PlayerLogic::getHeight(){
    return _ypos+70;
}
float PlayerLogic::getWidth(){
    return _xpos+40;
}

float PlayerLogic::getTheta()
{
    return _theta;
}

float PlayerLogic::degreesToRadians(float x)
{
    return (x * PI) / 180;
}

void PlayerLogic::playerMove(Direction dir)
{

    switch(dir)
    {
    case Direction::LEFT:
        moveLeftX();
        moveLeftY();
       
        _angleOfRotation = 4;
        break;
    case Direction::RIGHT:
       
        moveRightX();
        moveRightY();
        _angleOfRotation = -4;
        break;
    default:
        break;
    }

   
}