#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "PlayerLogic.h"
#include <memory>
#include <vector>
#include "PlayerBullet.h"
class GameLogic
{
public:
    GameLogic();

    void playerUpdate(Direction dir);
    
    void createPlayerBullet();
    
    void playerBulletUpdate();
    
    vector<PlayerBullet> getPlayerLogicBullets();

    PlayerLogic getPlayerLogic();

private:
 
 PlayerLogic player;
 
 
 vector<PlayerBullet> playerBulletLogicVector;
 
};

#endif // GAMELOGIC_H
