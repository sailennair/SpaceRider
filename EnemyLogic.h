#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H

#include "EnemyBulletLogic.h"

#include "GameCommonData.h"
#include "math.h"
#include <iostream>
#include "IEnemy.h"

class EnemyLogic : public IEnemy
{
public:
    EnemyLogic(int initalXposition, int initalYposition, float theta);

    void move();

    float getAngleofRotation();

    bool isAlive();

    void reduceHealth(int _damage);

    float getXposition();

    float getYposition();

    void setLife(bool life);

    bool isOutOfBounds();

    void setOutofBounds(bool outOfBounds);

    void moveToCenter(float xPosition, float yPosition, float theta);
    
    float getRadius();
    
    float getCenterXPosition();
    
    float getCenterYPosition();
    
    void setEnemySpeed(float speed);
    
    void setRadius(int radius);
    
    vector<EnemyBulletLogic> getEnemyBulletLogicVector();
    
    void clearEnemyBulletVector();
    
    void setEnemyBulletLife(bool life);
    
    
    
    


    // EnemyBulletLogic createEnemyBullet();

    //EnemyBulletLogic _enemyBulletLogic;

private:
vector<EnemyBulletLogic> enemyBulletLogicVector;

     int enemySize = 20;
    float _xpos;
    float _ypos;
    float _theta;
    bool _isAlive = true;
    int _health = 15;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.005;
    bool _outOfBounds = false;
    float _centerXPosition;
    float _centerYPosition;
    float _radius;
   
  
    // EnemyBulletLogic enemyBulletLogic;
};

#endif // ENEMYLOGIC_H
