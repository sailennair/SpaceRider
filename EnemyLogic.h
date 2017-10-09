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

    float getWidth();

    float getHeight();

    void moveToCenter(float xPosition, float yPosition, float theta);
    
    float getRadius();
    
    float getCenterXPosition();
    
    float getCenterYPosition();
    
    vector<EnemyBulletLogic> getEnemyBulletLogicVector();
    
      vector<EnemyBulletLogic> enemyBulletLogicVector;


    // EnemyBulletLogic createEnemyBullet();

    //EnemyBulletLogic _enemyBulletLogic;

private:
    float _theta;
    float _xpos;
    float _ypos;
    bool _isAlive = true;
    int _health = 15;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.0035;
    bool _outOfBounds = false;
    float _width;
    float _height;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
  
    // EnemyBulletLogic enemyBulletLogic;
};

#endif // ENEMYLOGIC_H
