#include "EnemyLogic.h"

EnemyLogic::EnemyLogic(int initalXposition, int initalYposition, float theta)
    : _xpos{ CenterXGameWindow - 10 }
    , _ypos{ CenterYGameWindow }
    , _theta{ theta }
    , _initialXposition{ CenterXGameWindow }
    , _initialYposition{ CenterXGameWindow }
    , _centerXPosition{ _xpos + enemySize }
    , _centerYPosition{ _ypos + enemySize }
    , _radius{ 15 }

{

    EnemyBulletLogic _enemyBulletLogic{ getXposition(), getYposition(), getAngleofRotation() };
    enemyBulletLogicVector.push_back(_enemyBulletLogic);
}

void EnemyLogic::move()
{
    _xpos += _initialXposition * cos(_theta) * _enemySpeed;
    _ypos += _initialYposition * sin(_theta) * _enemySpeed;

    _centerXPosition += (_initialXposition - 10) * cos(_theta) * _enemySpeed;
    _centerYPosition += (_initialYposition - 10) * sin(_theta) * _enemySpeed;

    if(enemyBulletLogicVector.size() > 0) {
        enemyBulletLogicVector[0].move();
    }
}

void EnemyLogic::moveToCenter(float xPosition, float yPosition, float theta)
{
    enemyBulletLogicVector.clear();

    EnemyBulletLogic _enemyBulletLogic{ xPosition, yPosition, theta };
    enemyBulletLogicVector.push_back(_enemyBulletLogic);

    _xpos = xPosition;
    _ypos = yPosition;
    _theta = theta;
    _centerXPosition = _xpos + enemySize;
    _centerYPosition = _ypos + enemySize;
}

vector<EnemyBulletLogic> EnemyLogic::getEnemyBulletLogicVector()
{
    return enemyBulletLogicVector;
}

float EnemyLogic::getAngleofRotation()
{
    return _theta;
}

bool EnemyLogic::isAlive()
{
    if(_health > 0) {
        return _isAlive;
    } else {
        return false;
    }
}

void EnemyLogic::reduceHealth(int _damage)
{
    _health -= _damage;
}

float EnemyLogic::getXposition()
{
    return _xpos;
}

float EnemyLogic::getYposition()
{
    return _ypos;
}

void EnemyLogic::setLife(bool life)
{
    _isAlive = life;
}

bool EnemyLogic::isOutOfBounds()
{
    return _outOfBounds;
}

void EnemyLogic::setOutofBounds(bool outOfBounds)
{
    _outOfBounds = outOfBounds;
}

float EnemyLogic::getRadius()
{
    return _radius;
}

float EnemyLogic::getCenterXPosition()
{
    return _centerXPosition;
}
float EnemyLogic::getCenterYPosition()
{
    return _centerYPosition;
}
void EnemyLogic::setEnemySpeed(float speed)
{
    _enemySpeed = speed;
}

void EnemyLogic::setRadius(int radius)
{
    _radius = radius;
}

void EnemyLogic::clearEnemyBulletVector()
{
    enemyBulletLogicVector.clear();
}

void EnemyLogic::setEnemyBulletLife(bool life)
{
    enemyBulletLogicVector[0].setLife(life);
}