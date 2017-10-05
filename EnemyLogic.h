#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H


#include "EnemyBulletLogic.h"
#include "IGameCharacter.h"
#include "GameCommonData.h"
#include "math.h"
#include <iostream>



class EnemyLogic 
{
public:
    EnemyLogic(  int initalXposition, int initalYposition, float theta );

    void move();

    float getAngleofRotation();

    bool isAlive();

    void reduceHealth(int _damage);

    float getXposition() ;

    float getYposition() ;
    
   // EnemyBulletLogic createEnemyBullet();
    
    
    EnemyBulletLogic _enemyBulletLogic;
    
    
    
private:
    float _theta;
    float _xpos;
    float _ypos;
    bool _life; 
    int _health;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.007;
    
    
    // EnemyBulletLogic enemyBulletLogic;
    
   
};

#endif // ENEMYLOGIC_H
