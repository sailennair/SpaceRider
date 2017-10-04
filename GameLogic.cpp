#include "GameLogic.h"

GameLogic::GameLogic()
{
    PlayerLogic player();
    
    
    
}

void GameLogic::playerUpdate(Direction dir){
    
  //  std:: cout<< player.getXposition()<<"  "<<player.getYposition()<< std::endl;
  //  std::cout<<"\n";
  
 player.playerMove(dir);
  
 //  std:: cout<< player.getXposition()<<"  "<<player.getYposition()<< "   "<<player.getTheta() <<std::endl;
    
}

