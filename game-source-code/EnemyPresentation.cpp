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

    EnemyBulletPresentation enemyBulletPresentation(CenterXGameWindow, CenterYGameWindow);
    _enemyBulletPresentationVector.push_back(enemyBulletPresentation);
}

EnemyPresentation::EnemyPresentation(int type)
{
    if(type == 1) {
        if(!enemySpriteTexture.loadFromFile("laserGenerator.png")) {
            std::cerr << "Error Loading Player Texture";
        }
        enemySpriteTexture.setSmooth(true);
        _enemySprite.setTexture(enemySpriteTexture);
        _enemySprite.setScale(Vector2f(0.6, 0.6));
        _enemySprite.setPosition(CenterXGameWindow, CenterYGameWindow);

        EnemyBulletPresentation enemyBulletPresentation(CenterXGameWindow, CenterYGameWindow);
        _enemyBulletPresentationVector.push_back(enemyBulletPresentation);
    }
}

void EnemyPresentation::draw(RenderWindow& window)
{

    if(_enemyBulletPresentationVector.size() > 0) {
        _enemyBulletPresentationVector[0].draw(window);
    }
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
}

void EnemyPresentation::updateEnemyBullet(float xPosition, float yPosition)
{

    if(_enemyBulletPresentationVector.size() > 0) {
        _enemyBulletPresentationVector[0].updateEnemyBullet(xPosition, yPosition);
    }
}

void EnemyPresentation::moveToCenter()
{

    _enemyBulletPresentationVector.clear();

    EnemyBulletPresentation enemyBulletPresentation(CenterXGameWindow, CenterYGameWindow);
    _enemyBulletPresentationVector.push_back(enemyBulletPresentation);
}

vector<EnemyBulletPresentation> EnemyPresentation::getEnemyBulletPresentationVector()
{
    return _enemyBulletPresentationVector;
}

void EnemyPresentation::deleteEnemyBulletPresentation()
{
    if(_enemyBulletPresentationVector.size() > 0) {
        _enemyBulletPresentationVector.clear();
    }
}