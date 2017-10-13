#include "EnemyBulletPresentation.h"

EnemyBulletPresentation::EnemyBulletPresentation(){
    //Default constructor is for the laser generator
    _enemyBullet.setFillColor(sf::Color::Red);
    _enemyBullet.setRadius(10);
}

EnemyBulletPresentation::EnemyBulletPresentation(float xPosition , float yPosition)
{
    _enemyBullet.setFillColor(sf::Color::Blue);
    _enemyBullet.setRadius(2.5);
}

void EnemyBulletPresentation::updateEnemyBullet(float xPosition , float yPosition){
    _enemyBullet.setPosition(xPosition, yPosition);
}

void EnemyBulletPresentation::draw(sf::RenderWindow &window){
   
    window.draw(_enemyBullet);
}

sf::CircleShape EnemyBulletPresentation::getEnemyBullet(){
    return _enemyBullet;
}