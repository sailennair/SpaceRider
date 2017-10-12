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
    void draw(RenderWindow& window);
    void updateEnemy(float xPosition, float yPosition);
    Sprite getEnemySprite();
    void updateEnemyBullet(float xPosition, float yPosition);
    void moveToCenter();
    vector<EnemyBulletPresentation> getEnemyBulletPresentationVector();
    void deleteEnemyBulletPresentation();
   
private:
    vector<EnemyBulletPresentation> _enemyBulletPresentationVector;
    Texture enemySpriteTexture;
    Sprite _enemySprite;
};

#endif // ENEMYPRESENTATION_H
