#ifndef PLAYERPRESENTATION_H
#define PLAYERPRESENTATION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"

//! Player Presentation Class - controls the presentation of the player.
/*! This class is responsible creating the player sprite and putting it at a position on the screen.
\author Sailen Nair and William Becerra
 *
*/

class PlayerPresentation
{
public:
    /** Default constructor Inititalise the player texture, default position and scale.
     *
     */
    PlayerPresentation();
    /** Returns the player sprite.
     * @return Sprite containing the players graphics.
     */
    sf::Sprite getPlayer();
    /** Draws the player sprite
     * @param window to draw the player on.
     */
    void draw(sf::RenderWindow& window);
    /** Rotates the player sprite by an angle.
     * @param angle Rotaion of the player in radians
     */
    void rotateSprite(float angle);
    /** Sets the position of the player sprite to the co-ordinates given by the paramenters
     * @param xPosition x co-ordinate to set players position
     * @param yPosition y co-ordinate to set players position
     */
    void setPositionofPlayer(float xPosition, float yPosition);
    /** Resets the player's sprite position to the default starting position.
     */
    void restartPlayerPresentation();

private:
    sf::Texture _playerSpaceshipTexture;

    sf::Sprite _Player;
};

#endif // PLAYERPRESENTATION_H