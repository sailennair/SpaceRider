#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "IBullet.h"
#include "PlayerLogic.h"

class PlayerBullet : public IBullet
{
public:
    PlayerBullet(int xPosition, int yPosition, float theta, int type);
    void move();
    void setDamage(int damage);
    int getDamage();
    bool isAlive();
    float getXposition();
    float getYposition();
    void setLife(bool life);
    void fire();
    float getRadius();
    float getCenterXPosition();
    float getCenterYPosition();

private:

float _theta;
    int _playerBulletXposition;
    int _playerBulletYposition;
    int _speedOfBullets = 15;
    int _damage = 5;
    bool _isAlive = true;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
};

#endif // PLAYERBULLET_H
