#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "IBullet.h"
#include "PlayerLogic.h"

class PlayerBullet : public IBullet
{
public:
    PlayerBullet(int xPosition, int yPosition, float theta);

    void moveLeftX();
    void moveLeftY();
    void moveRightX();
    void moveRightY();
    float getAngleofRotation();
    bool isAlive();
    int getXposition();
    int getYposition();
    void setDamage(int damage);
    int getDamage();
    
    void setLife(bool life);
    
    void fire();

private:
    int _playerBulletXposition;
    int _playerBulletYposition;
    float _theta;
    int _speedOfBullets = 25;
    int _damage;
    bool _isAlive = true;
};

#endif // PLAYERBULLET_H
