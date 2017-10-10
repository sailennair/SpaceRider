#include "LaserGeneratorPresentation.h"

LaserGeneratorPresentation::LaserGeneratorPresentation()
{

    for(auto i = 0; i < 2; i++) {
        EnemyPresentation laserGeneratorPresentation(1);
        laserGeneratorPresentationVector.push_back(laserGeneratorPresentation);
    }
std::cout<<"success"<<std::endl;
    for(auto i = 0; i < 20; i++) {
        EnemyBulletPresentation laserBulletPresentation;
        laserBulletPresentationVector.push_back(laserBulletPresentation);
    }
    std::cout<<"success111"<<std::endl;
}

void LaserGeneratorPresentation::draw(RenderWindow& window)
{

    for(auto& iter : laserBulletPresentationVector) {
        iter.draw(window);
    }
    for(auto& iter : laserGeneratorPresentationVector) {
        iter.draw(window);
    }
}

//vector<EnemyBulletPresentation> LaserGeneratorPresentation::getLaserBulletPresentationVector()
//{
//    return laserBulletPresentationVector;
//}

//void LaserGeneratorPresentation::updateLaserBulletPresentation(int index, float xPosition, float yPosition)
//{
//    if(laserBulletPresentationVector.size() > 0) {
//        laserBulletPresentationVector[index].updateEnemyBullet(xPosition, yPosition);
//    }
//}
