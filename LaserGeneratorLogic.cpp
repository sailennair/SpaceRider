#include "LaserGeneratorLogic.h"

// LaserGeneratorLogic::LaserGeneratorLogic(){}

LaserGeneratorLogic::LaserGeneratorLogic()
{

    float theta = 0;
    srand(time(0));
    _randomNumber = rand() % 2 + 1;

    if(_randomNumber == 1) {
        _theta = 0 * (PI / 1);

        for(auto i = 0; i < 2; i++) {
            EnemyLogic laserGeneratorEnemy(CenterXGameWindow, CenterYGameWindow, _theta + i * (PI / 8.375));
            laserGeneratorEnemy.setEnemySpeed(0.00285);
            laserGeneratorEnemy.setRadius(10);
            
            _laserGeneratorEnemyLogicVector.push_back(laserGeneratorEnemy);
        }

        for(auto i = 0; i < 20; i++) {
            theta += PI / 140;
            EnemyBulletLogic laserGeneratorBullets(CenterXGameWindow - 4, CenterYGameWindow + 3, _theta + theta);
            laserGeneratorBullets.setBulletSpeed(0.0029);
            laserGeneratorBullets.setDamage(0);
            _laserGeneratorEnemyBulletLogicVector.push_back(laserGeneratorBullets);
        }
    }

    if(_randomNumber == 2) {
        _theta = (PI);

        for(auto i = 0; i < 2; i++) {
            EnemyLogic laserGeneratorEnemy(CenterXGameWindow , CenterYGameWindow, _theta + i * (PI / 8.4));
            laserGeneratorEnemy.setEnemySpeed(0.00295);
            laserGeneratorEnemy.setRadius(10);
            
            _laserGeneratorEnemyLogicVector.push_back(laserGeneratorEnemy);
        }

        for(auto i = 0; i < 20; i++) {
            theta += _theta / 140;
            EnemyBulletLogic laserGeneratorBullets(CenterXGameWindow + 10, CenterYGameWindow + 10, _theta + theta);
            laserGeneratorBullets.setBulletSpeed(0.00295);
            laserGeneratorBullets.setDamage(0);
            _laserGeneratorEnemyBulletLogicVector.push_back(laserGeneratorBullets);
        }
    }
}

void LaserGeneratorLogic::move()
{

    for(auto& iter : _laserGeneratorEnemyLogicVector) {
        iter.move();
    }

    for(auto& iter : _laserGeneratorEnemyBulletLogicVector) {
        iter.move();
    }
}


 vector<EnemyLogic> LaserGeneratorLogic::getLaserGeneratorEnemyLogicVector(){
     return _laserGeneratorEnemyLogicVector;
 }
 
 void LaserGeneratorLogic::reduceHealthOfGenerator(int index, int damage){
     _laserGeneratorEnemyLogicVector[index].reduceHealth(damage);
 }
 
 void LaserGeneratorLogic::setGeneratorEnemyLife(int index,bool life){
      _laserGeneratorEnemyLogicVector[index].setLife(life);
 }
 
 vector<EnemyBulletLogic> LaserGeneratorLogic::getLaserGeneratorBulletLogicVector(){
     return _laserGeneratorEnemyBulletLogicVector;
 }