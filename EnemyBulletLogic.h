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

    bool isAlive();

    void setDamage(int damage);

    int getDamage();

    void setLife(bool life);

    float getWidth();

    float getHeight();

    float getRadius();
    
    float getCenterXPosition();
    
    float getCenterYPosition();

private:
    float _xPosition;

    float _yPosition;

    bool _isAlive;

    int _damage;

    float _bulletSpeed = 0.015;

    float _theta;

    float _initialXposition;

    float _initialYposition;

    float _width;

    float _height;
    
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
};

#endif // ENEMYBULLETLOGIC_H
