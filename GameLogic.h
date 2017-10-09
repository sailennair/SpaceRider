#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "PlayerLogic.h"
#include <memory>
#include <vector>
#include "PlayerBullet.h"
#include "EnemyLogic.h"
#include "CollisionDetection.h"
#include "SatelliteLogic.h"
#include "LifeLogic.h"


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
    
    void checkCollision();
    
    void createSatellites();
    
    void updateSatelliteLogic();
    
    void fireSatelliteBulletLogic();
    
    void checkSatelliteBulletScope();
    
    void setPlayerBulletType(int type);
    
    int getPlayerBulletType();
    
    void updatePlayerLife();
    
    int getPlayerLivesRemaining();
    
    LifeLogic getPlayerLifeLogic();
    
    vector<PlayerBullet> getPlayerLogicBullets();

    PlayerLogic getPlayerLogic();
    
    vector<PlayerBullet> playerBulletLogicVector;
    
    vector<EnemyLogic> enemyLogicVector;
    
    vector<SatelliteLogic> satelliteLogicVector;
    
    CollisionDetection collisionDetection;
    
    vector<EnemyBulletLogic> satelliteBulletLogic;
    
   
    
    

private:
 
 PlayerLogic player;
 
LifeLogic _lifeLogic;


 
 int _playerBulletType = 1;
 
 int _playerLifesRemaining;
 
 
 
};

#endif // GAMELOGIC_H
