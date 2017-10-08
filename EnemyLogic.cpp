#include "EnemyLogic.h"

EnemyLogic::EnemyLogic(int initalXposition, int initalYposition, float theta)
{

    _xpos = CenterXGameWindow;
    _ypos = CenterYGameWindow;
    _theta = theta;
    _initialXposition = CenterXGameWindow;
    _initialYposition = CenterXGameWindow;
    _width = 20;
    _height = 20;
    _centerXPosition = _xpos + 20;
    _centerYPosition = _ypos + 20;

    _radius = 15;

    EnemyBulletLogic _enemyBulletLogic{ getXposition(), getYposition(), getAngleofRotation() };
    //_enemyBulletLogic = enemyBulletLogic;

    enemyBulletLogicVector.push_back(_enemyBulletLogic);
}

void EnemyLogic::move()
{
    _xpos += _initialXposition * cos(_theta) * _enemySpeed;
    _ypos += _initialYposition * sin(_theta) * _enemySpeed;

    _centerXPosition += (_initialXposition - 10) * cos(_theta) * _enemySpeed;
    _centerYPosition += (_initialYposition - 10) * sin(_theta) * _enemySpeed;

    //_enemyBulletLogic.move();
    if(enemyBulletLogicVector.size()>0){
    enemyBulletLogicVector[0].move();
    
    }
}

void EnemyLogic::moveToCenter(float xPosition, float yPosition, float theta)
{
    
    enemyBulletLogicVector.clear();

    EnemyBulletLogic _enemyBulletLogic{ xPosition, yPosition, theta };
   // _enemyBulletLogic = enemyBulletLogic;
    enemyBulletLogicVector.push_back(_enemyBulletLogic);

    _xpos = xPosition;
    _ypos = yPosition;
    _theta = theta;

    _centerXPosition = _xpos + 20;
    _centerYPosition = _ypos + 20;
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

float EnemyLogic::getWidth()
{
    return _width;
}

float EnemyLogic::getHeight()
{
    return _height;
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