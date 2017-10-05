#ifndef ENEMYPRESENTATION_H
#define ENEMYPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <memory>
#include "EnemyBulletPresentation.h"

using namespace sf;
using namespace std;
class EnemyPresentation
{
public:
    EnemyPresentation();
   
   void draw(RenderWindow &window);
   
   void updateEnemy(float xPosition, float yPosition);
   
   Sprite getEnemySprite();
   
   Sprite _enemySprite;
   
   void updateEnemyBullet(float xPosition, float yPosition);
   
   EnemyBulletPresentation _enemyBulletPresentation;
   
private:
   
   
   Texture enemySpriteTexture;

};

#endif // ENEMYPRESENTATION_H
