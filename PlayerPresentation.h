#ifndef PLAYERPRESENTATION_H
#define PLAYERPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <memory>

using namespace std;
using namespace sf;

class PlayerPresentation
{
public:
    PlayerPresentation();

    Sprite getPlayer();

    void draw(RenderWindow& window);
    
    void rotateSprite(float angle);
    
     Sprite _Player;

private:
    Texture _playerSpaceshipTexture;
    
   
    
    RectangleShape _rect;
};

#endif // PLAYERPRESENTATION_H
