#include "GamePresentation.h"

GamePresentation::GamePresentation()
{
    PlayerPresentation _playerPresentation();
    
     gameLogic_shared_pointer = make_shared<GameLogic>();
   
}

void GamePresentation::upDatePosition(){
    
    
     
    _playerPresentation._Player.setPosition((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),(gameLogic_shared_pointer->getPlayerLogic()).getYposition());
    
    _playerPresentation._Player.rotate((gameLogic_shared_pointer->getPlayerLogic()).getAngleofRotation());
    
    
    
    
     
     //_playerPresentation._Player.setPosition(_gameLogic.player.getXposition(),_gameLogic.player.getYposition());
}

void GamePresentation::upDatePlayerBulletPresentation(){
    auto playerLogicbulletsVector = gameLogic_shared_pointer->getPlayerLogicBullets();
   // playerBulletPresentationVector.erase(playerLogicbulletsVector.begin(), playerLogicbulletsVector.end());
    
    for(auto iter = 0; iter < playerLogicbulletsVector.size(); iter++){
        PlayerBulletPresentation playerBulletPresentation(playerLogicbulletsVector[iter].getXposition(),playerLogicbulletsVector[iter].getYposition());
        playerBulletPresentationVector.push_back(playerBulletPresentation);
    }
}


void GamePresentation::renderSprite(RenderWindow &window){
   
   // upDatePosition();
    
    _playerPresentation.draw(window);
    
     for(auto iter = 0; iter < playerBulletPresentationVector.size(); iter++){
         std::cout <<"yes" <<std::endl;
        playerBulletPresentationVector[iter].draw(window);
    }
    
}
