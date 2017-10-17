#ifndef EXPLOSIONPRESENTATION_H
#define EXPLOSIONPRESENTATION_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>

//! Controls the presentation of the explosion effect.
/*! This class is responsible for controlling the explosion effect graphical representation.
\author Sailen Nair and William Becerra
 *
*/
class ExplosionPresentation
{
public:
/** Default constructor inititalise explosion effect texture, default position, type and scale.
 */
    ExplosionPresentation();
/** Constructor inititalise explosion effect texture, default position, type and scale.
 * @param x float containing x co-ordinate where the explosion effect should be created.
 * @param y float containing y co-ordinate where the explosion effect should be created
 */
    ExplosionPresentation(float x, float y);
 /** Draws the explosion effect in the screen defined by the parameter window.
 * @param window to draw the laer on.
 */   
    void draw(sf::RenderWindow& window);
    
private:
    sf::Sprite _explosion;
    sf::Texture _explosionTexture;
int _spriteSheetcount = 1;
int _yspriteSheetCount = 0;
int _count = 0;
};

#endif // EXPLOSIONPRESENTATION_H
