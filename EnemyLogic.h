#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H

#include "EnemyBulletLogic.h"
#include "IGameCharacter.h"
#include "GameCommonData.h"
#include "math.h"
#include <iostream>
//#include "IMovingGameObject.h"
class EnemyLogic: private IMovingGameObject
{
public:
    EnemyLogic(){};
    EnemyLogic(float initalXposition, float initalYposition, float theta);
    virtual ~EnemyLogic(){};

    void move();

    float getAngleofRotation();

    virtual bool isAlive() override;

    void reduceHealth(int _damage);

    virtual float getXposition()override;

    virtual float getYposition()override;

    void setLife(bool life);

    bool isOutOfBounds();

    void setOutofBounds(bool outOfBounds);

    virtual float getWidth()override;

    virtual float getHeight()override;

    void moveToCenter(float xPosition, float yPosition, float theta);
    
    vector<EnemyBulletLogic> getEnemyBulletLogicVector();

    // EnemyBulletLogic createEnemyBullet();

    EnemyBulletLogic _enemyBulletLogic;

private:
    float _theta;
    float _xpos;
    float _ypos;
    bool _isAlive;
    int _health;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.007;
    bool _outOfBounds = false;
    float _width;
    float _height;
    
    vector<EnemyBulletLogic> enemyBulletLogicVector;

    // EnemyBulletLogic enemyBulletLogic;
};

#endif // ENEMYLOGIC_H
