#include "LaserGeneratorLogic.h"

LaserGeneratorLogic::LaserGeneratorLogic()
{
    float laserAngleMovement1 = 8.375;
    float laserAngleMovement2 = 8.4;
    int numberOFLaserGenerators = 2;
    int numberOfLasers = 20;
    int radiusoflaserGenerators = 10;
    float LaserGeneratorMovementSpeed1 = 0.00285;
    float laserMovementSpeed1 = 0.0029;
    float laserMovementSpeed2 = 0.00295;
    float laserGeneratorSpeed2 = 0.00295;
    int angleDivision = 140;
    int laserOffset1 = 4;
    int laserOffset2 = 10;

    float theta = 0;
    srand(time(0));
    _randomNumber = rand() % 2 + 1;

    if(_randomNumber == 1) {
        _theta = 0 * (PI / 1);

        for(auto i = 0; i < numberOFLaserGenerators; i++) {
            EnemyLogic laserGeneratorEnemy(
                CenterXGameWindow, CenterYGameWindow, _theta + i * (PI / laserAngleMovement1));
            laserGeneratorEnemy.setEnemySpeed(LaserGeneratorMovementSpeed1);
            laserGeneratorEnemy.setRadius(radiusoflaserGenerators);

            _laserGeneratorEnemyLogicVector.push_back(laserGeneratorEnemy);
        }

        for(auto i = 0; i < numberOfLasers; i++) {
            theta += PI / angleDivision;
            EnemyBulletLogic laserGeneratorBullets(CenterXGameWindow - laserOffset1, CenterYGameWindow + laserOffset1, _theta + theta);
            laserGeneratorBullets.setBulletSpeed(laserMovementSpeed1);
            laserGeneratorBullets.setDamage(0);
            _laserGeneratorEnemyBulletLogicVector.push_back(laserGeneratorBullets);
        }
    }

    if(_randomNumber == 2) {
        _theta = (PI);

        for(auto i = 0; i < numberOFLaserGenerators; i++) {
            EnemyLogic laserGeneratorEnemy(CenterXGameWindow, CenterYGameWindow, _theta + i * (PI / laserAngleMovement2));
            laserGeneratorEnemy.setEnemySpeed(laserGeneratorSpeed2);
            laserGeneratorEnemy.setRadius(radiusoflaserGenerators);

            _laserGeneratorEnemyLogicVector.push_back(laserGeneratorEnemy);
        }

        for(auto i = 0; i < numberOfLasers; i++) {
            theta += _theta / angleDivision;
            EnemyBulletLogic laserGeneratorBullets(CenterXGameWindow + laserOffset2, CenterYGameWindow + laserOffset2, _theta + theta);
            laserGeneratorBullets.setBulletSpeed(laserMovementSpeed2);
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

std::vector<EnemyLogic> LaserGeneratorLogic::getLaserGeneratorEnemyLogicVector()
{
    return _laserGeneratorEnemyLogicVector;
}

void LaserGeneratorLogic::reduceHealthOfGenerator(int index, int damage)
{
    _laserGeneratorEnemyLogicVector[index].reduceHealth(damage);
}

void LaserGeneratorLogic::setGeneratorEnemyLife(int index, bool life)
{
    _laserGeneratorEnemyLogicVector[index].setLife(life);
}

std::vector<EnemyBulletLogic> LaserGeneratorLogic::getLaserGeneratorBulletLogicVector()
{
    return _laserGeneratorEnemyBulletLogicVector;
}