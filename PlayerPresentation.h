#ifndef PLAYERPRESENTATION_H
#define PLAYERPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <memory>

using namespace std;
using namespace sf;

class PlayerPresentation
{
public:
/**
 * Default constructor Inititalise the player texture, default position and scale. 
 *  
 */
    PlayerPresentation();
/**
 * @brief Returns the player sprite.
 * @return Sprite containing the players graphics.
 */
    Sprite getPlayer();
/**
 * @brief Draws the player sprite
 * @param window to draw the player on.
 */
    void draw(RenderWindow& window);
/**
 * @brief Rotates the player sprite by an angle.
 * @param angle Rotaion of the player in radians
 */
    void rotateSprite(float angle);
/**
 * @brief Sets the position of the player sprite to the co-ordinates given by the paramenters
 * @param xPosition x co-ordinate to set players position
 * @param yPosition y co-ordinate to set players position
 */
    void setPositionofPlayer(float xPosition, float yPosition);
/**
 * @brief Resets the player's sprite position to the default starting position.
 */
    void restartPlayerPresentation();

    
    
    

private:
    Texture _playerSpaceshipTexture;
    
    Sprite _Player;
};

#endif // PLAYERPRESENTATION_H
