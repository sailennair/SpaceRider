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

//! Enemy Presentation Class - contols the presentation of the main enemies.
/*! This class is responsible drawing and updating position of the enemy sprites.
\author Sailen Nair and William Becerra
 *
*/
class EnemyPresentation
{
public:
    /**
     *@brief Default constructor Inititalise the player texture, default position and scale.
     */
    EnemyPresentation();
    /**
     * @brief Constructor Inititalise the player texture, default position and scale for a type of enemy.
     * @param type specifies if enemy is normal enemy or laser generator enemy. type 1 for normal enemey and type 2
     * laser generator.
     */
    EnemyPresentation(int type);

    /** Draws the satellite sprite.
     * @param window to draw the enemy on.
     */
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