#include "EnemyBulletPresentation.h"

EnemyBulletPresentation::EnemyBulletPresentation(){
    //Default constructor is for the laser generator
    _enemyBullet.setFillColor(Color::Red);
    _enemyBullet.setRadius(10);}

EnemyBulletPresentation::EnemyBulletPresentation(float xPosition , float yPosition)
{
    _enemyBullet.setFillColor(Color::Blue);
    _enemyBullet.setRadius(2.5);
}


void EnemyBulletPresentation::updateEnemyBullet(float xPosition , float yPosition){
    _enemyBullet.setPosition(xPosition,yPosition);
}

void EnemyBulletPresentation::draw(RenderWindow &window){
   
    window.draw(_enemyBullet);
}

CircleShape EnemyBulletPresentation::getEnemyBullet(){
    return _enemyBullet;
}