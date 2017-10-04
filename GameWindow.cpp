#include "GameWindow.h"

GameWindow::GameWindow()
{
   
    GamePresentation _gamePresentation();
    
   
   
}



void GameWindow::generateWindow()
{
    sf::RenderWindow _window(sf::VideoMode(GameXWindow, GameYWindow), "My Window");
   
  
    _window.setVerticalSyncEnabled(true);
    
    
    while(_window.isOpen()) {

        sf::Event event;

        while(_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                _window.close();
                break;
            }
            if(event.key.code == sf::Keyboard::A){
                _direction = Direction::LEFT;
                 checkKeyBoardEvent();
            }
            
            if (event.key.code == sf::Keyboard::D){
                _direction = Direction::RIGHT;
                 checkKeyBoardEvent();
            }
            
            if(event.key.code == sf::Keyboard::Space){
                firePlayerBullet();
            }
            
        }
        
       
        _window.clear(sf::Color::Black);
        renderCharacters(_window);
         _window.display();
       
     
    }
}

void GameWindow::renderCharacters(RenderWindow &window){
   
    _gamePresentation.renderSprite(window);
    
}

void GameWindow::checkKeyBoardEvent()
{
       _gamePresentation.gameLogic_shared_pointer->playerUpdate(_direction);
       _gamePresentation.upDatePosition();
      _gamePresentation.upDatePlayerBulletPresentation();
}

void GameWindow::firePlayerBullet()
{
    _gamePresentation.gameLogic_shared_pointer->createPlayerBullet();
    
    
   // auto tempVector  = _gamePresentation.gameLogic_shared_pointer->getPlayerLogicBullets();
}

