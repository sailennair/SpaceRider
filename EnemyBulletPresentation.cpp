#include "EnemyBulletPresentation.h"

EnemyBulletPresentation::EnemyBulletPresentation(){
     _rect.setFillColor(Color::Red);
    _rect.setRadius(10);}

EnemyBulletPresentation::EnemyBulletPresentation(float xPosition , float yPosition)
{
     //_rect.setSize(Vector2f(5,5));
    _rect.setFillColor(Color::Blue);
    _rect.setRadius(2.5);
   // _rect.setPosition(xPosition,yPosition);
}


void EnemyBulletPresentation::updateEnemyBullet(float xPosition , float yPosition){
     //std::cout<<"drawingEnemyBullet"<<std::endl;
    _rect.setPosition(xPosition,yPosition);
}

void EnemyBulletPresentation::draw(RenderWindow &window){
   
    window.draw(_rect);
}

CircleShape EnemyBulletPresentation::getEnemyBullet(){
    return _rect;
}