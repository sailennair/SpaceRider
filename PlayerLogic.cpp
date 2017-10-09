#include "PlayerLogic.h"

using namespace std;
PlayerLogic::PlayerLogic()
{
    _xpos = PlayerXPosition;
    _ypos = PlayerYPosition;
    _health = PlayerHealth;
    _width = 40;
    _height = 70;
    _radius = 25;

    // This will be the center of the game width
    _centerXPosition = CenterXGameWindow;
    // this will be the center of the bottom of the y window minus half the height of the sprite
    _centerYPosition = GameYWindow - 40;

    //    _centerXPosition = PlayerXPosition;
    //    _centerYPosition = PlayerYPosition;
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
    _centerYPosition += yOrigin; // +25*sin(_theta);
}

void PlayerLogic::moveRightX()
{
    _theta = _theta + degreesToRadians(-2);
    _xpos = (radius)*cos(_theta);
    _xpos += xOrigin;

    _centerXPosition = (centerPlayerRadius)*cos(_theta);
    _centerXPosition += xOrigin + 10 * cos(_theta);
    // std::cout<<_theta<<std::endl;
}

void PlayerLogic::moveRightY()
{
    _theta = _theta + degreesToRadians(-2);
    _ypos = (radius)*sin(_theta);
    _ypos += yOrigin;

    _centerYPosition = (centerPlayerRadius)*sin(_theta);
    _centerYPosition += yOrigin; //+25*sin(_theta);
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

float PlayerLogic::getWidth()
{
    return _width;
}

float PlayerLogic::getHeight()
{
    return _height;
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