#include "SatellitePresentation.h"

SatellitePresentation::SatellitePresentation()
{
    _satellite.scale(sf::Vector2f(0.05, 0.05));

    if(!_satelliteTexture.loadFromFile("satellite.png")) {
        std::cerr << "Error Loading Player Texture";
    }
    _satelliteTexture.setSmooth(true);
    _satellite.setTexture(_satelliteTexture);

   _rect.setSize(Vector2f(5,5));
  _rect.setFillColor(sf::Color::Red);
}

void SatellitePresentation::draw(sf::RenderWindow& window, float x, float y)
{
    _satellite.setTexture(_satelliteTexture);
    _satellite.setPosition(sf::Vector2f(x, y));
    
    window.draw(_satellite);
 window.draw(_rect);
}

Sprite SatellitePresentation::getSprite()
{
    return _satellite;
}