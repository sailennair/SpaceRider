#include "LaserGeneratorPresentation.h"

LaserGeneratorPresentation::LaserGeneratorPresentation()
{

    int numberofLaserGenerators = 2;
    int numberofLasers = 20;
    
    for(auto i = 0; i < numberofLaserGenerators; i++) {
        EnemyPresentation laserGeneratorPresentation(1);
        laserGeneratorPresentationVector.push_back(laserGeneratorPresentation);
    }

    for(auto i = 0; i < numberofLasers; i++) {
        EnemyBulletPresentation laserBulletPresentation;
        laserBulletPresentationVector.push_back(laserBulletPresentation);
    }
}

void LaserGeneratorPresentation::draw(sf::RenderWindow& window)
{

    for(auto& iter : laserBulletPresentationVector) {
        iter.draw(window);
    }
    for(auto& iter : laserGeneratorPresentationVector) {
        iter.draw(window);
    }
}

vector<EnemyPresentation> LaserGeneratorPresentation::getLaserGeneratorPresentationVector()
{
    return laserGeneratorPresentationVector;
}

void LaserGeneratorPresentation::updateLaserGeneratorEnemy(int index, float xPosition, float yPosition)
{
    if(laserGeneratorPresentationVector.size() > 0) {
        laserGeneratorPresentationVector[index].updateEnemy(xPosition, yPosition);
    }
}

vector<EnemyBulletPresentation> LaserGeneratorPresentation::getLaserBulletPresentationVector()
{
    return laserBulletPresentationVector;
}

void LaserGeneratorPresentation::updateLaserBulletPresentation(int index, float xPosition, float yPosition)
{
    if(laserBulletPresentationVector.size() > 0) {
        laserBulletPresentationVector[index].updateEnemyBullet(xPosition, yPosition);
    }
}
