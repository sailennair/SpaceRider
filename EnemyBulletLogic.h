#ifndef ENEMYBULLETLOGIC_H
#define ENEMYBULLETLOGIC_H

//#include "IEnemyBullet.h"
#include "math.h"
#include "IBullet.h"
// class EnemyLogic;

class EnemyBulletLogic : public IBullet
{
public:
    EnemyBulletLogic();
    EnemyBulletLogic(float enemyXPosition, float enemyYPosition, float theta);
    void move();
    float getXposition();
    float getYposition();
    bool isAlive() ;
    void setDamage(int damage);
    int getDamage();
    void setLife(bool life);
    float getRadius();
    float getCenterXPosition();
    float getCenterYPosition();
    void setBulletSpeed(float speed);

private:

    float _xPosition;
    float _yPosition;
    bool _isAlive = true;
    int _damage = 5;
    float _bulletSpeed = 0.015;
    float _theta;
    float _initialXposition;
    float _initialYposition;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
    
};

#endif // ENEMYBULLETLOGIC_H
