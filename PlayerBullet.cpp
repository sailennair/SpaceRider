#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(int xPosition, int yPosition, float theta)
{
    _playerBulletXposition = xPosition;
    _playerBulletYposition = yPosition;
    _theta = theta;
    _width = 5;
    _height = 5;
    _centerXPosition = xPosition + 2.5;
    _centerYPosition = yPosition +2.5;
    _radius = 5;
}

// void PlayerBullet::moveLeftX()
//{
//    _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
//}
//
// void PlayerBullet::moveLeftY()
//{
//     _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) /
//     radius;
//    _playerBulletYposition = _playerBulletYposition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
//}
//
// void PlayerBullet::moveRightX()
//{
//    _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
//}
//
// void PlayerBullet::moveRightY()
//{
//    _playerBulletYposition = _playerBulletYposition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
//}

void PlayerBullet::move()
{

    _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;

    _playerBulletYposition = _playerBulletYposition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
    
    _centerXPosition = _centerXPosition  + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
    
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
    //  std::cout<<"fire"<<std::endl;
    move();
}

void PlayerBullet::setLife(bool life)
{
    _isAlive = life;
}

float PlayerBullet::getWidth()
{
    return _width;
}
float PlayerBullet::getHeight()
{
    return _height;
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