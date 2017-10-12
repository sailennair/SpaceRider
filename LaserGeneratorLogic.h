#ifndef LASERGENERATORLOGIC_H
#define LASERGENERATORLOGIC_H
#include "GameCommonData.h"
#include "EnemyLogic.h"
#include "EnemyBulletLogic.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <time.h>
#define PI 3.14159265

class LaserGeneratorLogic
{
public:
    LaserGeneratorLogic();

    void move();
    
    void reduceHealthOfGenerator(int index, int damage);
    
    void setGeneratorEnemyLife(int index,bool life);
    
    vector<EnemyLogic> getLaserGeneratorEnemyLogicVector();
    
    vector<EnemyBulletLogic> getLaserGeneratorBulletLogicVector();

private:
    vector<EnemyLogic> _laserGeneratorEnemyLogicVector;
    
    vector<EnemyBulletLogic> _laserGeneratorEnemyBulletLogicVector;

    float _theta;
    
    int _randomNumber;
};

#endif // LASERGENERATORLOGIC_H
