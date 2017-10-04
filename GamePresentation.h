#ifndef GAMEPRESENTATION_H
#define GAMEPRESENTATION_H

#include <SFML/Window.hpp>
#include "PlayerPresentation.h"
#include "GameLogic.h"
#include "GameCommonData.h"


class GamePresentation
{
public:
    GamePresentation();
    
    void renderSprite(RenderWindow &window);
    
    void checkEvent();
    
private:
    PlayerPresentation _playerPresentation;
    
   // GameWindow _gameWindow;
    GameLogic _gameLogic;

};

#endif // GAMEPRESENTATION_H
