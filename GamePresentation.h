#ifndef GAMEPRESENTATION_H
#define GAMEPRESENTATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerPresentation.h"
#include "GameLogic.h"
#include "GameCommonData.h"
#include <memory>
#include "PlayerBulletPresentation.h"
#include "EnemyPresentation.h"
#include <vector>
#include "SatellitePresentation.h"
#include "LifePresentation.h"
#include "LaserGeneratorPresentation.h"
#include "AsteroidPresentation.h"
#include "ScorePresentation.h"
#include "ExplosionPresentation.h"

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

//! Game Presentation class - class where logic and presentation layer meet
/*! This class creates objects for all the presentation objects. All the objects link to a specific logic object within
the Game Logic class.
\author Sailen Nair and William Becerra
 *
*/
using namespace std;

class GamePresentation
{
public:
    /**Default constructor, creats a shared pointer object of Game Logic.
     */
    GamePresentation();

    /**Draws the player sprite aswell as the amount of lives the player has remaining.
     * @param window
     */
    void renderPlayerSprite(RenderWindow& window);

    /**Gets the position of the player and updates the sprites position of the player.
     */
    void upDatePlayerPosition();

    /**Checks if the player has any lives left.
     * If the player loses a life, the player will be reset to the starting position.
     */
    void checkPlayerPresentationLifeDead();

    /**Updates the position of all the player bullets as well as the type of bullet.
     * Updates the position of the player bullet by retirving the location of the of the bullet from the logic class.
     * The function will also check how
     * many satellites have been killed, if more than 2 satellites have been killed the player bullet type is set to 2.
     */
    void upDatePlayerBulletPresentation();

    /**Creates a player bullet object at the current position of player.
     * The object is created and stored in a vector of type 'PlayerBulletPresentation'
     */
    void createPlayerBulletPresentation();

    /**Draws all the player bullets.
     * Function calls the draw function implemented within the Player bullet class.
     * @param window
     */
    void drawAllBullets(RenderWindow& window);

    /**Deletes the presentation objects of player bullets and satellite bullets when they go out of scope.
     * The function will chech if the satellite bullets and the player bullets are alive from the logic layer, if they
     * are not, their presentation objects are deleted.
     */
    void deleteOutofScopeBullets();

    /**Creates an object of Enemy presentation and adds it to a vector of of type 'EnemyPresentation'.
     */
    void createEnemyPresentationObject();

    /** Updates the presentation of the enemies and the enemy bullets.
     * The function updates the presentation of all the enemies and the enemy bullets. If the enemies go out of scope,
     * the function will call the 'moveToCenter'.
     */

    void updateEnemyPresentation();

    /**Will call the delete all enemies function, and the it will draw all the presentations of the enemies.
     * @param window
     */
    void drawAllEnemies(RenderWindow& window);

    /**Will delete the enemies and satelliet presentation objects that are set to dead in the logic domain
     */
    void deleteDeadEnemies();

    /**Creates an object of Satellite presentation and stores it in a vector of type 'SatellitePresentation'
     */
    void createSatellitePresenetation();

    /**Gets the position of the satellites and then draws the satellites.
     * @param window
     */
    void drawSatellites(RenderWindow& window);

    /**Funciton will delete all the enemy bullets whose lives are set to false in the logic layer.
     */
    void deleteDeadEnemyBullets();

    /**Will return the vector of satellite presentation objects.
     * @return Vector of type 'SatellitePresentation'
     */
    vector<SatellitePresentation> getSatellitePresentationVector();

    /**Creates bullets for the satellites that are still alive.
     * The bullets are stored in a vector of type 'EnemyBulletPresentation'
     */
    void createSatelliteBulletPresentation();

    /**Gets the position of all the satellite bullets and draws them.
     * @param window
     */
    void drawSatelliteBullets(RenderWindow& window);

    /**Retrieves the current lives remaining from the logic domain and sends it to the life presentation class.
     */
    void setPlayerLifeCount();

    /**Creates a single object of type 'LaserGeneratorPresentation' and stores it within a vector.
     */
    void createLaserGenerator();

    /**Draws the laser generator.
     * @param window
     */
    void drawLaserGenerator(RenderWindow& window);

    /**Updates the presentation of all the entities making up the laser generator.
     * The laser generator presentation is made up of enemy presentation and enemy bullet presentation. All these
     * objects are updated.
     */
    void updateLaserGeneratorPresentation();

    /**Will delete the laser generator presentation object.
     * If the laser generator life is set to false in the Logic domain then the presentation is deleted as well as a
     * call to the logic domain to delete the laser.
     */
    void deleteLaserGenerator();

    /**Creates an object of type 'AsteroidPresentation' and stores it within a vector.
     */
    void createAsteroidPresentation();

    /**Gets the position of the Asteroid from the logic domain and its presentation object is updated.
     */
    void updateAsteroidPresentation();

    /**Draws the Asteroid.
     * @param window
     */
    void drawAsteroid(RenderWindow& window);

    /**Deletes the asteroid presentation object if its 'isOutOfBounds' property is set to false in the logic domain.
     */
    void deleteOutofScopeAsteroidsPresentation();

    /**Retrieves the high score from the logic domain and sends it to the score presentation object.
     */
    void updateScorePresentation();

    /**Draws the score on the screen.
     * @param window
     */
    void drawScorePresentation(RenderWindow& window);

    /**Returns the amount of enemies have been killed.
     * @return number of enemies killed.
     */
    int getEnemiesKilled();

    /**Returns a vector of type 'EnemyPresentation' with the enemy presentation objects.
     * @return vector of type 'EnemyPresentation'
     */
    vector<EnemyPresentation> getEnemyPresentationVector();

    /**Returns a vector of type 'LaserGeneratorPresntation'.
     * @return vector of type 'LaserGeneratorPresntation'
     */
    vector<LaserGeneratorPresentation> getLaserGeneratorPresentation();

    /**Returns a vector of type 'AsteroidPresentation'.
     * @return vector of type 'AsteroidPresentation'.
     */
    vector<AsteroidPresentation> getAsteroidPresentationVector();

    shared_ptr<GameLogic> gameLogic_shared_pointer;

private:
    PlayerPresentation _playerPresentation;

    vector<PlayerBulletPresentation> playerBulletPresentationVector;

    vector<EnemyPresentation> enemyPresentationVector;

    vector<SatellitePresentation> satellitePresentationVector;

    LifePresentation _lifePresentation;

    vector<EnemyBulletPresentation> satelliteBulletPresentationVector;

    vector<LaserGeneratorPresentation> _laserGeneratorPresentation;

    vector<AsteroidPresentation> asteroidPresentationVector;

    ScorePresentation scorePresentation;

    int _enemiesKilled = 0;

    int _timer;

    int _satellitesKilled = 0;
};

#endif // GAMEPRESENTATION_H
