#include "EnemyBulletPresentation.h"

EnemyBulletPresentation::EnemyBulletPresentation(){}

EnemyBulletPresentation::EnemyBulletPresentation(float xPosition , float yPosition)
{
     _rect.setSize(Vector2f(5,5));
    _rect.setFillColor(Color::Red);
    _rect.setPosition(xPosition,yPosition);
}


void EnemyBulletPresentation::updateEnemyBullet(float xPosition , float yPosition){
     //std::cout<<"drawingEnemyBullet"<<std::endl;
    _rect.setPosition(xPosition,yPosition);
}

void EnemyBulletPresentation::draw(RenderWindow &window){
   
    window.draw(_rect);
}

RectangleShape EnemyBulletPresentation::getEnemyBullet(){
    return _rect;
}