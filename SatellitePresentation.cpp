#include "SatellitePresentation.h"

SatellitePresentation::SatellitePresentation()
{
    _satellite.scale(sf::Vector2f(0.05, 0.05));
    if(!_satelliteTexture.loadFromFile("satellite.png")) {
        std::cerr << "Error Loading Player Texture";
    }
    _satelliteTexture.setSmooth(true);
    _satellite.setTexture(_satelliteTexture);
}

void SatellitePresentation::draw(sf::RenderWindow& window, float x, float y)
{
    _satellite.setTexture(_satelliteTexture);
    _satellite.setPosition(sf::Vector2f(x, y));
    window.draw(_satellite);
}

Sprite SatellitePresentation::getSprite()
{
    return _satellite;
}