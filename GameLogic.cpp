#include "GameLogic.h"

GameLogic::GameLogic()
{
    PlayerLogic player();
    
    
    
}

void GameLogic::playerUpdate(){
    
   player.playerMove(Direction::LEFT);
   player.moveLeftX();
   std:: cout<< player.getXposition()<<"  "<<player.getYposition()<< std::endl;
    
}

