#ifndef ENEMYBULLETLOGIC_H
#define ENEMYBULLETLOGIC_H

//#include "IEnemyBullet.h"
#include "math.h"
//class EnemyLogic; 



class EnemyBulletLogic //: public IEnemyBullet
{
public:
EnemyBulletLogic();
     EnemyBulletLogic(float enemyXPosition, float enemyYPosition , float theta);
    
     void move();

     float getXposition();

     float getYposition();

     bool isAlive();
    
     void setDamage(int damage);
    
     int getDamage();
     
private:
     float _xPosition;
     
     float _yPosition;
     
     bool _isAlive = true;
     
     int _damage;
     
     float _bulletSpeed = 0.008;
     
     float _theta;
     
     float _initialXposition;
     
     float _initialYposition;
     

};

#endif // ENEMYBULLETLOGIC_H