#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "IBullet.h"
#include "PlayerLogic.h"

class PlayerBullet : public IBullet
{
public:
    PlayerBullet(int xPosition, int yPosition, float theta, int type);

    //    void moveLeftX();
    //    void moveLeftY();
    //    void moveRightX();
    //    void moveRightY();
    //

    void move();

    void setDamage(int damage);

    int getDamage();

    bool isAlive();

    float getXposition();

    float getYposition();

    float getWidth();

    float getHeight();

    void setLife(bool life);

    void fire();

    float getRadius();

    float getCenterXPosition();

    float getCenterYPosition();

private:
    int _playerBulletXposition;
    int _playerBulletYposition;
    float _theta;
    int _speedOfBullets = 15;
    int _damage = 5;
    bool _isAlive = true;
    int _width;
    int _height;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
};

#endif // PLAYERBULLET_H
