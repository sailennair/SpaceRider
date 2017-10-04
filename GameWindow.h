#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "GameLogic.h"
#include "GameCommonData.h"
#include "GamePresentation.h"
#include "CreateWindow.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class GameWindow
{
public:
    GameWindow();
    
    void checkEvent();
    
    void generateWindow();
    
    void renderCharacters(RenderWindow &window);
    
    GameLogic _gameLogic;
   
    
private:
   
    GamePresentation _gamePresentation;
    sf::RectangleShape rectangle;
     RenderWindow _window;
    
  
  

};

#endif // GAMEWINDOW_H
