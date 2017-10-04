#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "PlayerLogic.h"

class GameLogic
{
public:
    GameLogic();

    void playerUpdate();

private:
    PlayerLogic player;
};

#endif // GAMELOGIC_H
