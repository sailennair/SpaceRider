#include "EnemyPresentation.h"

EnemyPresentation::EnemyPresentation()
{

    if(!enemySpriteTexture.loadFromFile("spacestation.png")) {
        std::cerr << "Error Loading Player Texture";
    }
     enemySpriteTexture.setSmooth(true);
    _enemySprite.setTexture(enemySpriteTexture);
    _enemySprite.setScale(Vector2f(0.05, 0.05));
    _enemySprite.setPosition(CenterXGameWindow, CenterYGameWindow);
    
    EnemyBulletPresentation enemyBulletPresentation(CenterXGameWindow,CenterYGameWindow);
    _enemyBulletPresentation = enemyBulletPresentation;
}

void EnemyPresentation::draw(RenderWindow& window)
{
    _enemyBulletPresentation.draw(window);
    window.draw(_enemySprite);
    
   // window.draw(_enemyBulletPresentation.getEnemyBullet());
}

Sprite EnemyPresentation::getEnemySprite()
{
    return _enemySprite;
}

void EnemyPresentation::updateEnemy(float xPosition, float yPosition)
{
    _enemySprite.setTexture(enemySpriteTexture);
    _enemySprite.setPosition(xPosition, yPosition);
}

void EnemyPresentation::updateEnemyBullet(float xPosition, float yPosition){
    _enemyBulletPresentation.updateEnemyBullet(xPosition,yPosition);
    
}