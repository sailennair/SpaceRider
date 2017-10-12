#include "AsteroidLogic.h"

AsteroidLogic::AsteroidLogic(float theta)
    : _xpos{ CenterXGameWindow }
    , _ypos{ CenterYGameWindow }
    , _theta{ theta }
    , _initialXposition{ CenterXGameWindow }
    , _initialYposition{ CenterXGameWindow }
    , _centerXPosition{ _xpos + asteroidSize }
    , _centerYPosition{ _ypos + asteroidSize }
    , _radius{ 15 }
{

}

void AsteroidLogic::move()
{
    _xpos += _initialXposition * cos(_theta) * _enemySpeed;
    _ypos += _initialYposition * sin(_theta) * _enemySpeed;
    _centerXPosition += (_initialXposition - asteroidSize/2) * cos(_theta) * _enemySpeed;
    _centerYPosition += (_initialYposition - asteroidSize/2) * sin(_theta) * _enemySpeed;
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
void AsteroidLogic::setOutOfBounds(bool bounds)
{
    _outOfBounds = bounds;
}

bool AsteroidLogic::isOutOfBounds()
{
    return _outOfBounds;
}

float AsteroidLogic::getDamage()
{
    return _damage;
}