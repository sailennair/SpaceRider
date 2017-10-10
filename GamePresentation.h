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

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

using namespace std;

class GamePresentation
{
public:
    GamePresentation();

    void renderSprite(RenderWindow& window);

    void upDatePlayerPosition();
    
    void checkPlayerPresentationLifeDead();

    void upDatePlayerBulletPresentation();

    void createPlayerBulletPresentation();

    void drawAllBullets(RenderWindow& window);

    void deleteOutofScopeBullets();

    void createEnemyPresentationObject();

    void updateEnemyPresentation();

    void drawAllEnemies(RenderWindow& window);

    void deleteDeadEnemies();

    void createSatellitePresenetation();

    void drawSatellites(RenderWindow& window);

    void deleteDeadEnemyBullets();

    vector<SatellitePresentation> getSatellitePresentationVector();

    void createSatelliteBulletPresentation();

    void drawSatelliteBullets(RenderWindow& window);

    void setPlayerLifeCount();

    void createLaserGenerator();

    void drawLaserGenerator(RenderWindow& window);

    void updateLaserGeneratorPresentation();

    void deleteLaserGenerator();

    void createAsteroidPresentation();

    void updateAsteroidPresentation();

    void drawAsteroid(RenderWindow& window);
    
    void deleteOutofScopeAsteroidsPresentation();

    // vector<EnemyBulletPresentation> satelliteBulletPresentationVector;

    vector<EnemyPresentation> getEnemyPresentationVector();

    vector<LaserGeneratorPresentation> getLaserGeneratorPresentation();

    vector<AsteroidPresentation> getAsteroidPresentationVector();

    shared_ptr<GameLogic> gameLogic_shared_pointer;

    //  vector<LaserGeneratorPresentation> _laserGeneratorPresentation;

    // vector<AsteroidPresentation>  asteroidPresentationVector;

private:
    PlayerPresentation _playerPresentation;

    vector<PlayerBulletPresentation> playerBulletPresentationVector;

    vector<EnemyPresentation> enemyPresentationVector;

    vector<SatellitePresentation> satellitePresentationVector;

    LifePresentation _lifePresentation;

    ///
    vector<EnemyBulletPresentation> satelliteBulletPresentationVector;

    vector<LaserGeneratorPresentation> _laserGeneratorPresentation;

    vector<AsteroidPresentation> asteroidPresentationVector;

    // this is just a test variable
    int _timer;

    int _satellitesKilled = 0;
};

#endif // GAMEPRESENTATION_H
