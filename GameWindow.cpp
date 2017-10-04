#include "GameWindow.h"

GameWindow::GameWindow()
{
    GameLogic _gameLogic();
    GamePresentation _gamePresentation();
    CreateWindow _createGameWindow();
}

void GameWindow::checkEvent()
{
    //for(auto i = 0; i < 10; i++) {
        _gameLogic.playerUpdate(Direction::LEFT);
   // }
}

void GameWindow::generateWindow()
{
    sf::RenderWindow _window(sf::VideoMode(GameXWindow, GameYWindow), "My Window");
   
   rectangle.setSize(Vector2f(20,20));
   rectangle.setFillColor(sf::Color::Blue);
   rectangle.setPosition(300,300);
    _window.setVerticalSyncEnabled(true);
    
    
    while(_window.isOpen()) {

        sf::Event event;

        while(_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                _window.close();
                break;
            }
        }
        checkEvent();
        _window.clear(sf::Color::Black);
        renderCharacters(_window);
          //_window.draw(rectangle);
        _window.display();
       
     
    }
}

void GameWindow::renderCharacters(RenderWindow &window){
    window.draw(rectangle);
    _gamePresentation.renderSprite(window);
    
}