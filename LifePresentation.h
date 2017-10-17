#ifndef LIFEPRESENTATION_H
#define LIFEPRESENTATION_H

#include <SFML/Graphics.hpp>
//! Controls the presentation of the Life indicator.
/*! This class is responsible for controlling the player's life indicator graphical representation.
\author Sailen Nair and William Becerra
 *
*/

class LifePresentation
{
public:
/** Default constructor inititalise the life indicator texture, default position, type and scale. 
 */
    LifePresentation();
/** Draws the Life indicator in the screen. 
 * The life indicator is draw at position defined by the parameters.
 * @param window to draw the life on.
 * @param x float containing x co-ordinate to draw the life indicator.
 * @param y float containing y co-ordinate to draw the life indicator
 */
    void draw(sf::RenderWindow& window, float x, float y);
/** Setter function to set how many lifes the life indicator should display.
 * The life count works on 5 lives maximum  and a minimum of 1 live
 * any other life counts by default will not be displayed on screen. 
 * @param count integer containing the number of lives the life indicator should display
 */
    void setLifeCount(int count);

private:
    void createSprite();

    void drawLoop(sf::RenderWindow& window, int iterations, float x, float y);

    sf::Texture _lifeTexture;

    sf::Sprite _lifeSprite;

    int _lifeCount;
};

#endif