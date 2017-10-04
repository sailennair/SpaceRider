#include "GamePresentation.h"

GamePresentation::GamePresentation()
{
    PlayerPresentation _playerPresentation();
    GameLogic _gameLogic();
   
}

void GamePresentation::checkEvent(){
     _gameLogic.playerUpdate(Direction::RIGHT);
}

void GamePresentation::renderSprite(RenderWindow &window){
   
    checkEvent();
    
    _playerPresentation._Player.setPosition(_gameLogic.player.getXposition(),_gameLogic.player.getYposition());
    
    std::cout<<_gameLogic.player.getXposition()<<"   " <<_gameLogic.player.getYposition()<<std::endl;
    
    _playerPresentation.draw(window);
}
