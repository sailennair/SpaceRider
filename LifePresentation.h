#ifndef LIFEPRESENTATION_H
#define LIFEPRESENTATION_H

#include <SFML/Graphics.hpp>
class LifePresentation{
public:
    LifePresentation();
    void draw(sf::RenderWindow& window, float x, float y);
    void setLifeCount(int count);
private:
    void createSprite();
    void drawLoop(sf::RenderWindow& window, int iterations, float x, float y);
    
    sf::Texture _lifeTexture;
    sf::Sprite _lifeSprite;
    
    int _lifeCount;
};

#endif