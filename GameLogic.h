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
#include "LaserGeneratorLogic.h"
#include "AsteroidLogic.h"

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

    void updateLaserLogic();

    void createLaserGeneratorLogic();

    void checkLaserGeneratorScope();

    void createAsteroid();

    void updateAsteroidLogic();

    LifeLogic getPlayerLifeLogic();

    vector<LaserGeneratorLogic> getlaserGeneratorLogic();

    void deleteLaserGenerator();

    vector<PlayerBullet> getPlayerLogicBullets();

    void deletePlayerBullet(int index);

    PlayerLogic getPlayerLogic();
    
    vector<EnemyLogic>  getEnemyLogicVector();
    
    void deleteEnemyLogic(int index);
    
    void setEnemyBounds(bool isInBounds, int index);
    
    void moveEnemyToCenter(int index);
    
    void clearEnemyBullet(int index);
    
    vector<SatelliteLogic> getSatelliteLogicVector();
    
    void deleteSatelliteLogic(int index);
    
    vector<EnemyBulletLogic> getSatellietBulletLogicVector();
    
    void deleteSatelliteBulletLogic(int index);
    
    void updateSatelliteBullets(int index);
    
    vector<AsteroidLogic> getAsteroidLogicVector();

     //vector<LaserGeneratorLogic> _laserGeneratorLogic;

    // vector<PlayerBullet> playerBulletLogicVector;

    //vector<EnemyLogic> enemyLogicVector;

    //vector<SatelliteLogic> satelliteLogicVector;


    //vector<EnemyBulletLogic> satelliteBulletLogic;

   // vector<AsteroidLogic> asteroidLogicVector;

private:
    PlayerLogic player;

    LifeLogic _lifeLogic;

    CollisionDetection collisionDetection;

    /////
    vector<LaserGeneratorLogic> _laserGeneratorLogic;

    vector<PlayerBullet> playerBulletLogicVector;
    
    vector<EnemyLogic> enemyLogicVector;
    
    vector<SatelliteLogic> satelliteLogicVector;
    
    vector<EnemyBulletLogic> satelliteBulletLogic;
    
    vector<AsteroidLogic> asteroidLogicVector;

    int _playerBulletType = 1;

    int _playerLifesRemaining;
};

#endif // GAMELOGIC_H
