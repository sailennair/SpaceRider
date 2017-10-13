#include "AsteroidLogic.h"

AsteroidLogic::AsteroidLogic(float theta):
    _xpos{ CenterXGameWindow },
    _ypos{ CenterYGameWindow },
    _theta{ theta },
    _isAlive{ true },
    _health{ 10000 },
    _initialXposition{ CenterXGameWindow },
    _initialYposition{ CenterXGameWindow },
    _enemySpeed{ 0.005 },
    _outOfBounds{ false },
    _asteroidSize{ 20 },
    _centerXPosition{ _xpos + _asteroidSize },
    _centerYPosition{ _ypos + _asteroidSize },
    _radius{ 15 },
    _damage{ 20 }
{

}

void AsteroidLogic::move()
{
    _xpos += _initialXposition * cos(_theta) * _enemySpeed;
    _ypos += _initialYposition * sin(_theta) * _enemySpeed;
    _centerXPosition += (_initialXposition - _asteroidSize/2) * cos(_theta) * _enemySpeed;
    _centerYPosition += (_initialYposition - _asteroidSize/2) * sin(_theta) * _enemySpeed;
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