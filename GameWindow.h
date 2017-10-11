#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include "GamePresentation.h"
#include "GameLogic.h"
#include "GameCommonData.h"
#include <vector>
#include <memory>
#include "IntroductionWindow.h"
#include "FinalWindow.h"

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
    
    void updatePlayer();
    
    void updateAllEnemies();
    
    void runGame();
    
    
    
    
   
   
    
private:
   
    GamePresentation _gamePresentation;
  
    RenderWindow _window;
    
    Direction _direction;
    
    IntroductionWindow introductionWindow;
    
    FinalWindow finalWindow;
    
   
    
    
  
  

};

#endif // GAMEWINDOW_H
