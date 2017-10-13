#ifndef SATELLITEPRESENTATION_H
#define SATELLITEPRESENTATION_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameCommonData.h"

//! Controls the presentation of the satellite.
/*! This class is responsible creating the satellite sprite and putting it at a position on the screen.
\author Sailen Nair and William Becerra
 *
*/

class SatellitePresentation
{
public:
/** Default constructor inititalise the satellite texture and default scale.
 */
    SatellitePresentation();
/** Draws the satellite sprite.
 * @param window to draw the satellite on.
 */
    void draw(sf::RenderWindow& window, float x, float y);
/** Returns the satellite sprite.
 * @return Sprite containing the satellite graphics.
 */
    sf::Sprite getSprite();

private:
    sf::Sprite _satellite;
    sf::Texture _satelliteTexture;
};

#endif // SATELLITEPRESENTATION_H