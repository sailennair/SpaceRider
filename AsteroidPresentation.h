#ifndef ASTEROIDPRESENTATION_H
#define ASTEROIDPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <string>

using namespace sf;
class AsteroidPresentation
{
public:
    AsteroidPresentation();
    
    void draw(RenderWindow &window);
    
    void updateAsteroid(float xPosition, float yPosition);
private:
char _spriteSheetcount = 0;
 Sprite _asteroidSprite;
 Texture _asteroidTexture;
};

#endif // ASTEROIDPRESENTATION_H
