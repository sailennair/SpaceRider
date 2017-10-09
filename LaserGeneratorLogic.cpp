#include "LaserGeneratorLogic.h"

// LaserGeneratorLogic::LaserGeneratorLogic(){}

LaserGeneratorLogic::LaserGeneratorLogic()
{

    float theta =0;
    srand(time(0));
    _randomNumber = rand() % 2 + 1;

    if(_randomNumber == 1) {
        _theta = 0 * (PI / 1);

        for(auto i = 0; i < 2; i++) {
            EnemyLogic laserGeneratorEnemy(CenterXGameWindow , CenterYGameWindow , _theta + i *(PI / 8.35) );
            laserGeneratorEnemy.setEnemySpeed(0.00285);
            laserGeneratorEnemy.setRadius(7);
            _laserGeneratorEnemyLogicVector.push_back(laserGeneratorEnemy);
        }

        for(auto i = 0; i < 70; i++) {
            theta  += PI/140;
            EnemyBulletLogic laserGeneratorBullets(CenterXGameWindow -4, CenterYGameWindow +3 , _theta + theta);
            laserGeneratorBullets.setBulletSpeed(0.0029);
            _laserGeneratorEnemyBulletLogicVector.push_back(laserGeneratorBullets);
        }
    }

    if(_randomNumber == 2) {
        _theta = (PI);

        for(auto i = 0; i < 2; i++) {
            EnemyLogic laserGeneratorEnemy(CenterXGameWindow -200, CenterYGameWindow, _theta + i * (PI / 8.4) );
            laserGeneratorEnemy.setEnemySpeed(0.00295);
            laserGeneratorEnemy.setRadius(7);
            _laserGeneratorEnemyLogicVector.push_back(laserGeneratorEnemy);
        }
        

        for(auto i = 0; i < 70; i++) {
            theta  +=_theta/140; 
            EnemyBulletLogic laserGeneratorBullets(
                CenterXGameWindow + 10, CenterYGameWindow + 10, _theta + theta);
            laserGeneratorBullets.setBulletSpeed(0.00295);
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
