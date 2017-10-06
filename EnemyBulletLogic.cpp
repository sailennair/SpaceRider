#include "EnemyBulletLogic.h"


EnemyBulletLogic::EnemyBulletLogic(){}
EnemyBulletLogic::EnemyBulletLogic(float enemyXPosition, float enemyYPosition, float theta)
{
    _xPosition = enemyXPosition;
    _yPosition = enemyYPosition;
    _theta = theta;
    _initialXposition = enemyXPosition;
    _initialYposition = enemyYPosition;
    _width = 5;
    _height =5;
    
}

void EnemyBulletLogic::move()
{
    _xPosition += _initialXposition*cos(_theta)*_bulletSpeed;
    
    _yPosition += _initialYposition*sin(_theta)*_bulletSpeed;
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

float EnemyBulletLogic::getWidth(){
    return _width;
}

float EnemyBulletLogic::getHeight(){
    return _height;
}
