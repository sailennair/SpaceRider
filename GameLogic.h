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
    /**Constructor Inititalise the Game Logic Class.
    * Creates objects of Logic classes needed for all functions.
    */
    GameLogic();

    /**Update the Position of the player.
     * Move the players logic either left or right depending on the paramter passed back.
     * @param dir - this is the direction that player needs to move. of Type Direction
     */
    void playerUpdate(Direction dir);

    /**Creates and object for player Bullet.
     * The object is inserted into a vector of type PlayerBullet.
     */
    void createPlayerBullet();

    /**Updates the position of every player bullet object that is in the vector.
     * An iterator is will traverse through the vector and call the player bullet move function
     */
    void playerBulletUpdate();

    /**Checks the location of the player bullet.
     * If the player bullet reaches the center co-ordiniates of the window then the player bullet life is set to false.
     */
    void checkBulletScope();

    /**Creates and object of Enemy Logic at the center co-ordinates of the game and puts it into a vector of type
     * EnemyLogic.
     */
    void createEnemyLogicObject();

    /**Update the position all the enemy logic objects within the vector.
     * All the enemies will move in the direction given to them at the point of creation
     */
    void updateEnemyLogic();

    /**Checks if any of the enemies have gone out of the window of the game.
     * If the enemy has gone out of the window, the 'isOutOfBounds' property is set to true
     */
    void checkEnemyScope();

    /**Checks if player and player bullets have collided with any enemies.
     *Function will check if the player has collied with any enemy bullet. If it has collied with a enemy bullet or
     *enemy, its health will be reduced by the allocated damage of the enemy or enemy bullet.
     * Once the enemy bullet has collided with the player, its life is set to false.
     * The function also checks collision between all the player bullets and the enemies, asteroids, satellites and
     *laser generators. If a collision is detected, the enemy's healthis the reduced by the allocated damage of the
     *player bullet. The player bullet is then set to false.
     */
    void checkCollision();

    /**Creates three satellite objects, in front of the player and stores it in a vector of type SatelliteLogic.
     * This function will create three satellite objects infront of the player. It will use the current location of the
     * player and then create three satellites at a certain distance away from the player.
     */
    void createSatellites();

    /**Calls the move fucnction of the satellite.
     * This function will call the move function of the satellites, which will update its x and y co-ordinates. It will
     * do this for all the satellites within the SatelliteLogic Vector.
     */
    void updateSatelliteLogic();

    /**Creates a bullet of type EnemyBulletLogic for each satellite that is alive.
     * The bullets are created at the position of the satellites and are given the current angle of the player, thus the
     * stallite bullet will move towards the players location at the bullet was created.
     */

    void fireSatelliteBulletLogic();

    /**Checks if the satellite bullet has gone of the screen of the game.
     *If the bullet has gone off the screen the bullets life is set to false.
     */
    void checkSatelliteBulletScope();

    /**Sets the player bullet type to the paramter passed in.
     * @param type
     * The type is only 1 or 2
     */
    void setPlayerBulletType(int type);

    /**This will return the type number of the player bullet.
     * @return integer defining the type of the player bullet.
     */
    int getPlayerBulletType();

    /**This will set the amount of lives the player has left.
     * This function will get the current health of the player and then use LifeLogic to calculate and set the amount of
     * lives the player has remaining.
     */
    void updatePlayerLife();

    /**Function will return the amount of lives the player has left.
     * @return integer value of the amount of lives remaining.
     */
    int getPlayerLivesRemaining();

    /**Will update the movement of the laser generator.
     * This fucntion will move and update all the entities of the laser generator.
     */
    void updateLaserLogic();

    /**Creates an object of LaserGeneratorLogic and stores it within a vector of type LaserGeneratorLogic.
     */
    void createLaserGeneratorLogic();

    /**Checks if the laser generator enemies have gone off the screen.
     * If either of the laser generator enemies are gone off scope, their lives are set to false. This will ensure that
     * the laser generators will be deleted once they go off screen.
     */
    void checkLaserGeneratorScope();

    /**Creates an asteroid that will move in  the direction of the player at the point the asteroid was created.
     * The asteroid is created and put into a vector of type AsteroidLogic.
     */
    void createAsteroid();
    /**Will call the move function of each asteroid which will move the asteroid and update its position.
     * The asteroid wil move according to its move fucntion, its x and y co-ordinates will be updated.
     */
    void updateAsteroidLogic();

    /**Checks if the asteroid is on screen or not.
     * If the asteroid goes out of bounds, its 'isOutOfBounds' property is set to false.
     */
    void checkAsteroidBounds();

    /**This will delete an asteroid at the position in the vector that is passed in as a paramter.
     * @param index - the position in the vector that will be deleted.
     */
    void deleteOutOfScopeAsteroids(int index);

    /**Checks if the player current lives remaining is less than the lives remaining variable.
     * If the current lives are less than the lives remaining variable, then the lives remaining variable is made to
     equal the current lives. If the player has lost a life, it will then set the player logic x and y co-ordinates to
     the defualt.
     * @return true if the player has lost a life, false if the player has not.
     */
    bool checkPlayerLifeDead();

    /**Checks if the player is dead.
     * If the players live is equal to or less than 0, then the player is considered dead.
     * @return true if the player is dead, false if not.
     */
    bool isPlayerDead();

    /**This will return the object of the players life.
     * @return an object of type LifeLogic.
     */
    LifeLogic getPlayerLifeLogic();

    /**This will return the vector of Laser generators.
     * @return a vector of type LaserGeneratorLogic
     */
    vector<LaserGeneratorLogic> getlaserGeneratorLogic();

    /**This will clear the entire vector of LaserGenerators.
     * Since there is only laser generator on the screen at any point in time, by clearing the entire vector, the only
     * laser generator will be deleted.
     */
    void deleteLaserGenerator();

    /**This will return a vector with all the player bullet objects stored within.
     * @return a vector of type PlayerBullet.
     */
    vector<PlayerBullet> getPlayerLogicBullets();

    /**Will delete the player object stored in the vector at location passed into the fucntion.
     * @param index - the poisition within the vector, where the player bullet that is going to be deleted is storred.
     */
    void deletePlayerBullet(int index);

    /**Will return the PlayerLogic object.
     * @return an object of type PlayerLogic
     */
    PlayerLogic getPlayerLogic();

    /**Will return a vector with all the enemy objects storred within.
     * @return a vector of type EnemyLogic.
     */
    vector<EnemyLogic> getEnemyLogicVector();
    /**Will delete an enemy from the enemy Logic vector, and increase the player score.
     * The enemy at the position parsed into the funciton will be deleted as will as the player score will increase by
     * 15 points.
     * @param index - position of enemy to be deleted within the vector.
     */
    void deleteEnemyLogic(int index);

    /**Will set the enemy 'isOutOfBounds' property to whateevr is parsed into the funciton
     * @param isInBounds - boolean
     * @param index - position at which the enemy is in the vector.
     */
    void setEnemyBounds(bool isInBounds, int index);

    /**This will call the moveToCenter fucntion of the enemy and will place the enemy in the middle of the screen.
     * @param index - posiiton in the vector where the enemy that needs to be moved to the center is.
     */
    void moveEnemyToCenter(int index);

    /**This will delete the enemy bullet that is within the enemy logic object.
     * Enemy logic only has one bullet, hence the entire vector can be cleared.
     * @param index - position of enemy within the vector
     */
    void clearEnemyBullet(int index);

    /**This will return the vector where the satellite objects are stored.
     * @return a vector of type SatelliteLogic
     */
    vector<SatelliteLogic> getSatelliteLogicVector();

    /**This will delete the satellite at position 'index' within the vector, the score will also increase.
     * When a satellite is deleted the score is increased by 25.
     * @param index - position where the satellite is stored within the vector.
     */
    void deleteSatelliteLogic(int index);

    /**Will return a vector of the Satelliet bullet objects.
     * @return a vector of type SatelliteBulletLogic
     */
    vector<EnemyBulletLogic> getSatellietBulletLogicVector();

    /**Will delete the satellite bullet object stored at position 'index'
     * @param index - position at which the object is stored within the vector.
     */
    void deleteSatelliteBulletLogic(int index);

    /**Will call the move function for the satellite bullet, the x and y co-ordinate will get updated.
     * @param index - position of the satellite bullet object that will be updated.
     */
    void updateSatelliteBullets(int index);

    /**This will return the Asteroid vector where the asteroid objects are stored.
     * @return vector of type AsteroidLogic.
     */
    vector<AsteroidLogic> getAsteroidLogicVector();

    /**This will save the current score to a text file.
     * The storeScore function from the Score class will be called which will save the current score to a hidden
     * textfile.
     */
    void saveScoretoFile();

    /**This will get the Highest score ever achieved in the game.
     * @return the highest score ever to be achieved in the game.
     */
    int getHighScore();

    /**The current score of the player is returned.
     * @return the current score of the player.
     */
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
