#ifndef ASTEROIDPRESENTATION_H
#define ASTEROIDPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <string>


//! Controls the presentation of the Asteroid.
/*! This class is responsible creating the asteroid sprite and putting it at a position on the screen.
\author Sailen Nair and William Becerra
 *
*/

class AsteroidPresentation
{
public:
/** Default constructor inititalise the asteroid texture, default position and scale.
 */
    AsteroidPresentation();
/** Draws the asteroid sprite.
 * @param window to draw the asteroid on.
 */
    void draw(sf::RenderWindow& window);
/** Updates the asteroid sprite position as the asteroid moves.
 *  @param xPosition float containing the x co-ordinate the asteroid has moved to.
 *  @param yPosition float containing the y co-ordinate the asteroid has moved to.
 */
    void updateAsteroid(float xPosition, float yPosition);
 /** Returns the asteroid sprite.
  * @return Sprite containing the asteroid graphics.
  */   
    sf::Sprite getAsteroidSprite();

private:
    char _spriteSheetcount = 0;
    sf::Sprite _asteroidSprite;
    sf::Texture _asteroidTexture;
};



#endif // ASTEROIDPRESENTATION_H
