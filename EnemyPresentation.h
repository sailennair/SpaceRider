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
/**
 * Default constructor Inititalise the player texture, default position and scale. 
 */
    EnemyPresentation();
    /**
     * @brief Constructor Inititalise the player texture, default position and scale for a type of enemy.
     * @param window the window to draw the enemy into.
     */
    EnemyPresentation(int type);
    void draw(RenderWindow& window);
    /**
     * @brief Updates the enemy Sprite's position after the enemy has moved.
     * @param xPosition  x co-ordinate the enemy has moved to.
     * @param yPosition y co-ordinate the enemy has moved to.
     */
    void updateEnemy(float xPosition, float yPosition);
    /**
     * @brief Returns the enemy Sprite.
     * @return Sprite containing the enemy graphics.
     */
    Sprite getEnemySprite();
    /**
     * @brief Updates the position of an enemy bullet.
     * @param xPosition x co-ordinate the bullet has moved to.
     * @param yPosition
     */
    void updateEnemyBullet(float xPosition, float yPosition);
    /**
     * @brief Moves enemy Sprite to the center of the screen
     */
    void moveToCenter();
    /**
     * @brief Returns a vector of EnemyBulletPresentation.
     * @return EnemyBulletPresentation contianing the graphics of all enemy bullets
     */
    vector<EnemyBulletPresentation> getEnemyBulletPresentationVector();
    /**
     * @brief Deletes the EnemyBulletPresentation vector
     */
    void deleteEnemyBulletPresentation();
   
private:
    vector<EnemyBulletPresentation> _enemyBulletPresentationVector;
    Texture enemySpriteTexture;
    Sprite _enemySprite;
};

#endif // ENEMYPRESENTATION_H
