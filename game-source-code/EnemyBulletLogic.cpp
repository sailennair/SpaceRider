#include "EnemyBulletLogic.h"

EnemyBulletLogic::EnemyBulletLogic()
{
}
EnemyBulletLogic::EnemyBulletLogic(float enemyXPosition, float enemyYPosition, float theta)
    : _theta{ theta }
    , _initialXposition{ enemyXPosition }
    , _initialYposition{ enemyYPosition }
    , _radius{ 5 }
{
    _xPosition = enemyXPosition + (2 * _radius) * cos(_theta);
    _yPosition = enemyYPosition + (2 * _radius) * sin(_theta);
    _centerXPosition = _xPosition - _radius;
    _centerYPosition = _yPosition - _radius;
}

void EnemyBulletLogic::move()
{
    _xPosition += _initialXposition * cos(_theta) * _bulletSpeed;
    _yPosition += _initialYposition * sin(_theta) * _bulletSpeed;
    _centerXPosition += _initialXposition * cos(_theta) * _bulletSpeed;
    _centerYPosition += _initialYposition * sin(_theta) * _bulletSpeed;
}

float EnemyBulletLogic::getXposition()
{
    return _xPosition;
}

float EnemyBulletLogic::getYposition()
{
    return _yPosition;
}

bool EnemyBulletLogic::isAlive()
{
    return _isAlive;
}

void EnemyBulletLogic::setDamage(int damage)
{
    _damage = damage;
}

int EnemyBulletLogic::getDamage()
{
    return _damage;
}

void EnemyBulletLogic::setLife(bool life)
{
    _isAlive = life;
}

float EnemyBulletLogic::getRadius()
{
    return _radius;
}

float EnemyBulletLogic::getCenterXPosition()
{
    return _centerXPosition;
}

float EnemyBulletLogic::getCenterYPosition()
{
    return _centerYPosition;
}

void EnemyBulletLogic::setBulletSpeed(float speed)
{
    _bulletSpeed = speed;
}