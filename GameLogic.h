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

//! Game Logic Class - Controls all logic entities of the game.
/*! This class controls all the logic entities of the game and is responsible for creating, deleting and manipulating
all game logic objects.
\author Sailen Nair and William Becerra
 *
*/

class GameLogic
{
public:
    /**
    * @brief Constructor Inititalise the Game Logic Class
    * Creates objects of Logic classes needed for all functions.
    */
    GameLogic();

    /**
     * @brief Update the Position of the player.
     * Move the players logic either left or right depending on the paramter passed back.
     * @param dir - this is the direction that player needs to move. of Type Direction
     */
    void playerUpdate(Direction dir);

    /**
     * @brief  Creates and object for player Bullet.
     * The object is inserted into a vector of type PlayerBullet.
     */
    void createPlayerBullet();

    /**
     * @brief Updates the position of every player bullet object that is in the vector.
     * An iterator is will traverse through the vector and call the player bullet move function
     */
    void playerBulletUpdate();
    
    /**
     * @brief 
     */

  //  void updatePlayerBulletLogic();

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

    vector<EnemyLogic> getEnemyLogicVector();

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

    int getCurrentScore();

private:
    PlayerLogic player;

    LifeLogic _lifeLogic;

    CollisionDetection collisionDetection;

    Score score;

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
