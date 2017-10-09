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
//LaserGeneratorLogic();
    LaserGeneratorLogic();

    void move();
    
    vector<EnemyLogic> _laserGeneratorEnemyLogicVector;
    
    vector<EnemyBulletLogic> _laserGeneratorEnemyBulletLogicVector;
    

private:
//    vector<EnemyLogic> _laserGeneratorEnemyLogicVector;
//    
//    vector<EnemyBulletLogic> _laserGeneratorEnemyBulletLogicVector;

    float _theta;
    
    int _randomNumber;
};

#endif // LASERGENERATORLOGIC_H
