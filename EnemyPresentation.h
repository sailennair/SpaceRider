#ifndef ENEMYPRESENTATION_H
#define ENEMYPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <memory>
#include "EnemyBulletPresentation.h"


#include "EnemyLogic.h"

using namespace sf;
using namespace std;
class EnemyPresentation
{
public:
    EnemyPresentation();
    
    EnemyPresentation(int type);
   
   void draw(RenderWindow &window);
   
   void updateEnemy(float xPosition, float yPosition);
   
   Sprite getEnemySprite();
   
   Sprite _enemySprite;
   
   void updateEnemyBullet(float xPosition, float yPosition);
   
   void moveToCenter();
   
    vector<EnemyBulletPresentation> getEnemyBulletPresentationVector();
    
    void deleteEnemyBulletPresentation();
   
  // EnemyBulletPresentation _enemyBulletPresentation;
   
   CircleShape _circle;
   
   //vector<EnemyBulletPresentation> _enemyBulletPresentationVector;
   
private:
   
   vector<EnemyBulletPresentation> _enemyBulletPresentationVector;
   
   Texture enemySpriteTexture;

};

#endif // ENEMYPRESENTATION_H
