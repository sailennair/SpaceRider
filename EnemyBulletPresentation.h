#ifndef ENEMYBULLETPRESENTATION_H
#define ENEMYBULLETPRESENTATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameCommonData.h"
#include <memory>

using namespace sf;

class EnemyBulletPresentation
{
public:
    EnemyBulletPresentation();
    
    EnemyBulletPresentation(float xPosition , float yPosition);
    
    void draw(RenderWindow &window);
    
    void updateEnemyBullet(float xPosition , float yPosition);
    
    RectangleShape getEnemyBullet();
   
   
   
private:

  RectangleShape _rect;
   
    
    

};

#endif // ENEMYBULLETPRESENTATION_H
