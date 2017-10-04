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
    _theta = _theta + degreesToRadians(-2);
    _xpos = (radius)*cos(_theta);
}

void PlayerLogic::moveLeftY()
{
    _theta = _theta + degreesToRadians(-2);
    _ypos = (radius)*sin(_theta);
}

void PlayerLogic::moveRightX()
{
    _theta = _theta + degreesToRadians(2);
    _xpos = (radius)*cos(_theta);
}

void PlayerLogic::moveRightY()
{
    _theta = _theta + degreesToRadians(2);
    _ypos = (radius)*sin(_theta);
}

void PlayerLogic::setAngleofRotation(int angle)
{

    _angleOfRotation = angle;
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

int PlayerLogic::getXposition()
{
    return _xpos;
}

int PlayerLogic::getYposition()
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
    if(dir == Direction::LEFT) {
        moveLeftX();
        moveLeftY();
    }

    if(dir == Direction::RIGHT) {
        moveRightX();
        moveRightY();
    }
}