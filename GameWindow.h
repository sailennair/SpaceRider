#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include "GamePresentation.h"
#include "GameLogic.h"
#include "GameCommonData.h"
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

using namespace sf;
class GameWindow
{
    
public:
    GameWindow();
    
    void checkKeyBoardEvent();
    
    void generateWindow();
    
    void renderCharacters(RenderWindow &window);
    
    void firePlayerBullet();
    
    void updatePlayerBullets();
    
    void updateAllEnemies();
    
    
    
    
   
   
    
private:
   
    GamePresentation _gamePresentation;
  
    RenderWindow _window;
    
    Direction _direction;
    
   
    
    
  
  

};

#endif // GAMEWINDOW_H
