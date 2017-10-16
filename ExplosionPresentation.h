#ifndef EXPLOSIONPRESENTATION_H
#define EXPLOSIONPRESENTATION_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>

class ExplosionPresentation
{
public:
ExplosionPresentation();
    ExplosionPresentation(float x, float y);
    
    void draw(sf::RenderWindow& window);
    
private:
    sf::Sprite _explosion;
    sf::Texture _explosionTexture;
int _spriteSheetcount = 1;
int _yspriteSheetCount = 0;
int _count = 0;
};

#endif // EXPLOSIONPRESENTATION_H
