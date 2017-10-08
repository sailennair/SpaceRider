#include "EnemyPresentation.h"

EnemyPresentation::EnemyPresentation()
{

    if(!enemySpriteTexture.loadFromFile("spacestation.png")) {
        std::cerr << "Error Loading Player Texture";
    }
     enemySpriteTexture.setSmooth(true);
    _enemySprite.setTexture(enemySpriteTexture);
    _enemySprite.setScale(Vector2f(0.1, 0.1));
    _enemySprite.setPosition(CenterXGameWindow, CenterYGameWindow);
    
    
    _circle.setRadius(5);
    _circle.setFillColor(sf::Color::Red);
    
    EnemyBulletPresentation enemyBulletPresentation(CenterXGameWindow,CenterYGameWindow);
    _enemyBulletPresentation = enemyBulletPresentation;
}

void EnemyPresentation::draw(RenderWindow& window)
{
    _enemyBulletPresentation.draw(window);
    window.draw(_circle);
    window.draw(_enemySprite);
    
  
}

Sprite EnemyPresentation::getEnemySprite()
{
    return _enemySprite;
}

void EnemyPresentation::updateEnemy(float xPosition, float yPosition)
{
    _enemySprite.setTexture(enemySpriteTexture);
    _enemySprite.setPosition(xPosition, yPosition);
   // _circle.
}

void EnemyPresentation::updateEnemyBullet(float xPosition, float yPosition){
    _enemyBulletPresentation.updateEnemyBullet(xPosition,yPosition);
    
}