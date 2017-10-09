#include "LifePresentation.h"
#include <iostream>
LifePresentation::LifePresentation():_lifeCount{5}
{
    createSprite();
}
void LifePresentation::draw(sf::RenderWindow& window, float x, float y){
    switch (_lifeCount)        //Life Amount
    {
        case 5:       //100
            drawLoop(window, 5, x, y);
            break;
        case 4:     //80
            drawLoop(window, 4, x, y);
            break;
        case 3:     //60
            drawLoop(window, 3, x, y);
            break;
        case 2:     //40
            drawLoop(window, 2, x, y);
            break;
        case 1:     //20
            drawLoop(window, 1, x, y);
            break;
        default:
           break;//do nothing
 
        
    }
    
    
}

void LifePresentation::createSprite(){
    if(!_lifeTexture.loadFromFile("LifeHeart.png")) {
        std::cerr << "Error Loading Life Texture";
    }
    
    _lifeTexture.setSmooth(true);
    _lifeSprite.setTexture(_lifeTexture);
    _lifeSprite.setScale(sf::Vector2f(0.07, 0.07));
}


void LifePresentation::setLifeCount(int count){
    _lifeCount = count;
}

void LifePresentation::drawLoop(sf::RenderWindow& window, int iterations, float x, float y){
    float xpos = x;
    float ypos = y;

    for(auto i = iterations; i > 0; i--){
        _lifeSprite.setPosition(sf::Vector2f(xpos, ypos));
        window.draw(_lifeSprite);
        xpos+=25;
    }
}