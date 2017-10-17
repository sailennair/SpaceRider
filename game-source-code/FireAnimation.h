#ifndef FIREANIMATION_H
#define FIREANIMATION_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>

//! Controls the presentation of the fire effect.
/*! This class is responsible for controlling the fire effect graphical representation.
\author Sailen Nair and William Becerra
 *
*/
class FireAnimation
{
public:
    /**Defualt constructor.
     */
    FireAnimation();
    /**Connstructor that sets the location of the animation.
     * @param x - co ordinate
     * @param y = co-ordinate
     */
    FireAnimation(float x, float y);
    /**Draws the fire animation.
     * @param window
     */
    void draw(sf::RenderWindow& window);

private:
    sf::Sprite _explosion;
    sf::Texture _explosionTexture;
    int _spriteSheetcount = 0;
    int _yspriteSheetCount = 0;
    int _count = 0;
};

#endif // FIREANIMATION_H
