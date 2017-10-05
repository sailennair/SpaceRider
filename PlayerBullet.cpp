#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(int xPosition, int yPosition, float theta)
{
    _playerBulletXposition = xPosition;
    _playerBulletYposition = yPosition;
    _theta = theta;
}

void PlayerBullet::moveLeftX()
{
    _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
}

void PlayerBullet::moveLeftY()
{
    _playerBulletYposition = _playerBulletYposition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
}

void PlayerBullet::moveRightX()
{
    _playerBulletXposition = _playerBulletXposition + _speedOfBullets * (CenterXGameWindow - getXposition()) / radius;
}

void PlayerBullet::moveRightY()
{
    _playerBulletYposition = _playerBulletYposition + _speedOfBullets * (CenterYGameWindow - getYposition()) / radius;
}

float PlayerBullet::getAngleofRotation()
{
    return _theta;
}

bool PlayerBullet::isAlive()
{
    return _isAlive;
}

int PlayerBullet::getXposition()
{
    return _playerBulletXposition;
}

int PlayerBullet::getYposition()
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

void PlayerBullet::fire(){
  //  std::cout<<"fire"<<std::endl;
    moveLeftX();
    moveLeftY();
}

void PlayerBullet::setLife(bool life){
    _isAlive = life;
}