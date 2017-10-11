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
#include "Score.h"

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
    
    void checkAsteroidBounds();
    
    void deleteOutOfScopeAsteroids(int index);
    
    bool checkPlayerLifeDead();
    
    bool isPlayerDead();

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
    
    void saveScoretoFile();
    
    int getHighScore();
    


private:
    PlayerLogic player;

    LifeLogic _lifeLogic;

    CollisionDetection collisionDetection;
    
    Score score;
    
    

    /////
    vector<LaserGeneratorLogic> _laserGeneratorLogic;

    vector<PlayerBullet> playerBulletLogicVector;
    
    vector<EnemyLogic> enemyLogicVector;
    
    vector<SatelliteLogic> satelliteLogicVector;
    
    vector<EnemyBulletLogic> satelliteBulletLogic;
    
    vector<AsteroidLogic> asteroidLogicVector;

    int _playerBulletType = 1;

    int _playerLifesRemaining;
    
    int _currentLife = 5;
};

#endif // GAMELOGIC_H
