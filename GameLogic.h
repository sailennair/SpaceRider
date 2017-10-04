#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "PlayerLogic.h"

class GameLogic
{
public:
    GameLogic();

    void playerUpdate(Direction dir);
    
     PlayerLogic player;

private:
   
};

#endif // GAMELOGIC_H
