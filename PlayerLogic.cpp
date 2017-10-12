#include "PlayerLogic.h"

using namespace std;
PlayerLogic::PlayerLogic()
    : _xpos{ PlayerXPosition }
    , _ypos{ PlayerYPosition }
    , _health{ PlayerHealth }
    , _radius{ 25 }
    , _centerXPosition{ CenterXGameWindow }
    , _centerYPosition{ GameYWindow - PlayerHeight / 2 }
{
}

void PlayerLogic::playerRestart()
{
    _xpos = PlayerXPosition;
    _ypos = PlayerYPosition;
    _centerXPosition = CenterXGameWindow;
    _centerYPosition = GameYWindow - 40;
    _theta = (PI) / 2;
    _angleOfRotation = 0;
}

void PlayerLogic::moveLeftX()
{
    _theta = _theta + degreesToRadians(2);
    _xpos = (radius)*cos(_theta);
    _xpos += xOrigin;
    _centerXPosition = (centerPlayerRadius)*cos(_theta);
    _centerXPosition += xOrigin + 10 * cos(_theta);
}

void PlayerLogic::moveLeftY()
{
    _theta = _theta + degreesToRadians(2);
    _ypos = (radius)*sin(_theta);
    _ypos += yOrigin;
    _centerYPosition = (centerPlayerRadius)*sin(_theta);
    _centerYPosition += yOrigin; 
}

void PlayerLogic::moveRightX()
{
    _theta = _theta + degreesToRadians(-2);
    _xpos = (radius)*cos(_theta);
    _xpos += xOrigin;
    _centerXPosition = (centerPlayerRadius)*cos(_theta);
    _centerXPosition += xOrigin + 10 * cos(_theta);
  
}

void PlayerLogic::moveRightY()
{
    _theta = _theta + degreesToRadians(-2);
    _ypos = (radius)*sin(_theta);
    _ypos += yOrigin;
    _centerYPosition = (centerPlayerRadius)*sin(_theta);
    _centerYPosition += yOrigin; 
}

float PlayerLogic::getAngleofRotation()
{

    return _angleOfRotation;
}

bool PlayerLogic::isAlive()
{

    if(_health > 0) {
        _life = true;
    } else {
        _life = false;
    }

    return _life;
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
    switch(dir) {
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

float PlayerLogic::getRadius()
{
    return _radius;
}

float PlayerLogic::getCenterXPosition()
{
    return _centerXPosition;
}

float PlayerLogic::getCenterYPosition()
{
    return _centerYPosition;
}

int PlayerLogic::getHealth()
{
    return _health;
}

bool PlayerLogic::setLife(bool life)
{
    _life = life;
}