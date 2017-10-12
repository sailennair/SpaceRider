#ifndef SATELLITEPRESENTATION_H
#define SATELLITEPRESENTATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameCommonData.h"
#include <memory>

using namespace sf;

class SatellitePresentation
{

public:
    SatellitePresentation();

    void draw(RenderWindow& window, float x, float y);

    Sprite getSprite();


private:
    Sprite _satellite;
    Texture _satelliteTexture;
};

#endif // SATELLITEPRESENTATION_H