#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "PlayerLogic.h"
#include <memory>
#include <vector>
#include "PlayerBullet.h"
#include "EnemyLogic.h"
#include "IMovingGameObject.h"
class GameLogic
{
public:
    GameLogic();

    void playerUpdate(Direction dir);
    
    void createPlayerBullet();
    
    void playerBulletUpdate();
    
    void updatePlayerBulletLogic();
    
    void checkBulletScope();
    
    void createEnemyLogicObject();
    
    void updateEnemyLogic();
    
    void checkEnemyScope();
    
    vector<PlayerBullet> getPlayerLogicBullets();

    PlayerLogic getPlayerLogic();
    
    vector<PlayerBullet> playerBulletLogicVector;
    
    vector<EnemyLogic> enemyLogicVector;
    
    

private:
 
 PlayerLogic player;
 
 
 
 
};

#endif // GAMELOGIC_H
