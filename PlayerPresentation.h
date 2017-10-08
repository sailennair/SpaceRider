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
       CircleShape _rect;

private:
    Texture _playerSpaceshipTexture;
    
   
    
  
};

#endif // PLAYERPRESENTATION_H
