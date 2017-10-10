#include "AsteroidLogic.h"

AsteroidLogic::AsteroidLogic(float theta)
{

    _xpos = CenterXGameWindow - 8;
    _ypos = CenterYGameWindow;
    _theta = theta;
    _initialXposition = CenterXGameWindow;
    _initialYposition = CenterXGameWindow;
    _width = 20;
    _height = 20;
    _centerXPosition = _xpos + 20;
    _centerYPosition = _ypos + 20;

    _radius = 15;
}

void AsteroidLogic::move()
{
    _xpos += _initialXposition * cos(_theta) * _enemySpeed;
    _ypos += _initialYposition * sin(_theta) * _enemySpeed;

    _centerXPosition += (_initialXposition - 10) * cos(_theta) * _enemySpeed;
    _centerYPosition += (_initialYposition - 10) * sin(_theta) * _enemySpeed;
}

float AsteroidLogic::getAngleofRotation()
{
    return _theta;
}

bool AsteroidLogic::isAlive()
{
    return _isAlive;
}

void AsteroidLogic::reduceHealth(int _damage)
{
}

float AsteroidLogic::getXposition()
{
    return _xpos;
}

float AsteroidLogic::getYposition()
{
    return _ypos;
}

void AsteroidLogic::setLife(bool life)
{
    _isAlive = life;
}

float AsteroidLogic::getWidth()
{
    return _width;
}

float AsteroidLogic::getHeight()
{
    return _height;
}

float AsteroidLogic::getRadius()
{
    return _radius;
}

float AsteroidLogic::getCenterXPosition()
{
    return _centerXPosition;
}

float AsteroidLogic::getCenterYPosition()
{
    return _centerYPosition;
}
void AsteroidLogic::setOutOfBounds(bool bounds){
    _outOfBounds = bounds;
}

bool AsteroidLogic::isOutOfBounds(){
    return _outOfBounds;
}

float AsteroidLogic::getDamage(){
    return _damage;
}