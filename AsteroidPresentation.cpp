#include "AsteroidPresentation.h"

AsteroidPresentation::AsteroidPresentation()
{

    if(!_asteroidTexture.loadFromFile("asteroid2.png")) {
        std::cerr << "Error Loading Player Texture";
    }
    _asteroidTexture.setSmooth(true);
    _asteroidSprite.setTexture(_asteroidTexture);
    _asteroidSprite.setTextureRect(sf::IntRect(0,72,72,72 ));
    _asteroidSprite.setScale(Vector2f(0.75, 0.75));
    _asteroidSprite.setPosition(CenterXGameWindow, CenterYGameWindow);
}

void AsteroidPresentation::draw(RenderWindow& window)
{
   
    if(_spriteSheetcount >=5){
        _spriteSheetcount = 0;
    }
    _asteroidSprite.setTexture(_asteroidTexture);
    _asteroidSprite.setTextureRect(sf::IntRect(72*_spriteSheetcount, 72 ,72,72 ));
    window.draw(_asteroidSprite);
     _spriteSheetcount++;
}

void AsteroidPresentation::updateAsteroid(float xPosition, float yPosition)
{
    _asteroidSprite.setPosition(xPosition, yPosition);
}