#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(int xPosition, int yPosition, float theta, int type)
    : _theta{ theta }
{
    _playerBulletXposition = xPosition + PlayerWidth * cos(_theta);
    _playerBulletYposition = yPosition + (PlayerHeight / 2) * sin(_theta);

    if(type == 1) {

        _radius = 3;
        _damage = 5;
    }
    if(type == 2) {

        _radius = 6;
        _damage = 20;
    }

    _centerXPosition = xPosition + _radius / 2;
    _centerYPosition = yPosition + _radius / 2;
}

void PlayerBullet::move()
{

    _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
    _playerBulletYposition = _playerBulletYposition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
    _centerXPosition = _centerXPosition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
    _centerYPosition = _centerYPosition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
}

bool PlayerBullet::isAlive()
{
    return _isAlive;
}

float PlayerBullet::getXposition()
{
    return _playerBulletXposition;
}

float PlayerBullet::getYposition()
{
    return _playerBulletYposition;
}

void PlayerBullet::setDamage(int damage)
{
    _damage = damage;
}

int PlayerBullet::getDamage()
{
    return _damage;
}

void PlayerBullet::fire()
{
    move();
}

void PlayerBullet::setLife(bool life)
{
    _isAlive = life;
}

float PlayerBullet::getRadius()
{
    return _radius;
}

float PlayerBullet::getCenterXPosition()
{
    return _centerXPosition;
}

float PlayerBullet::getCenterYPosition()
{
    return _centerYPosition;
}