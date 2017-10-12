#include "GamePresentation.h"

GamePresentation::GamePresentation()
{

    gameLogic_shared_pointer = make_shared<GameLogic>();
    ScorePresentation scorePresentation(gameLogic_shared_pointer->getHighScore());
}

void GamePresentation::updateScorePresentation()
{
    scorePresentation.setScoreMessage(gameLogic_shared_pointer->getHighScore());
}

void GamePresentation::drawScorePresentation(RenderWindow& window)
{
    scorePresentation.setScoreMessage(gameLogic_shared_pointer->getHighScore());
    scorePresentation.draw(window, 10, 10);
}

void GamePresentation::upDatePlayerPosition()
{

    _playerPresentation.setPositionofPlayer((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),
        (gameLogic_shared_pointer->getPlayerLogic()).getYposition());
    _playerPresentation.rotateSprite((gameLogic_shared_pointer->getPlayerLogic()).getAngleofRotation());
}

void GamePresentation::checkPlayerPresentationLifeDead()
{
    if(gameLogic_shared_pointer->checkPlayerLifeDead() == true) {
        _playerPresentation.restartPlayerPresentation();
        upDatePlayerPosition();
    }
}

void GamePresentation::renderSprite(RenderWindow& window)
{

    _playerPresentation.draw(window);

    _lifePresentation.draw(window, gameLogic_shared_pointer->getPlayerLifeLogic().getXpos(),
        gameLogic_shared_pointer->getPlayerLifeLogic().getYpos());
}

void GamePresentation::setPlayerLifeCount()
{
    gameLogic_shared_pointer->updatePlayerLife();
    _lifePresentation.setLifeCount(gameLogic_shared_pointer->getPlayerLivesRemaining());
}

void GamePresentation::createPlayerBulletPresentation()
{
    PlayerBulletPresentation playerBulletPresentation((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),
        (gameLogic_shared_pointer->getPlayerLogic()).getYposition(), gameLogic_shared_pointer->getPlayerBulletType());
    playerBulletPresentationVector.push_back(playerBulletPresentation);
}

void GamePresentation::upDatePlayerBulletPresentation()
{
    int numberofSatellitesKilledNeededFoGunUpGrade = 3;
    if(_satellitesKilled >= numberofSatellitesKilledNeededFoGunUpGrade &&
        _satellitesKilled % numberofSatellitesKilledNeededFoGunUpGrade == 0) {
        gameLogic_shared_pointer->setPlayerBulletType(2);
    }
    for(unsigned int index = 0; index < unsigned(playerBulletPresentationVector.size()); index++) {
        playerBulletPresentationVector[index].updateBullet(
            gameLogic_shared_pointer->getPlayerLogicBullets()[index].getXposition(),
            gameLogic_shared_pointer->getPlayerLogicBullets()[index].getYposition());
    }
}

void GamePresentation::drawAllBullets(RenderWindow& window)
{
    deleteOutofScopeBullets();
    for(auto& iter : playerBulletPresentationVector) {
        iter.draw(window);
    }
}

void GamePresentation::deleteOutofScopeBullets()
{
    for(unsigned int iter = 0; iter < unsigned(playerBulletPresentationVector.size()); iter++) {
        if(playerBulletPresentationVector.size() > 0 && gameLogic_shared_pointer->getPlayerLogicBullets().size() > 0) {
            if(gameLogic_shared_pointer->getPlayerLogicBullets()[iter].isAlive() == false) {
                playerBulletPresentationVector.erase(playerBulletPresentationVector.begin() + iter);
                gameLogic_shared_pointer->deletePlayerBullet(iter);
            }
        }
    }
    for(unsigned int index = 0; index < unsigned(satelliteBulletPresentationVector.size()); index++) {
        if(satelliteBulletPresentationVector.size() > 0) {
            if(gameLogic_shared_pointer->getSatellietBulletLogicVector()[index].isAlive() == false) {
                gameLogic_shared_pointer->deleteSatelliteBulletLogic(index);
                satelliteBulletPresentationVector.erase(satelliteBulletPresentationVector.begin() + index);
            }
        }
    }
}

void GamePresentation::createEnemyPresentationObject()
{
    EnemyPresentation enemyPresentation;
    enemyPresentationVector.push_back(enemyPresentation);
}

void GamePresentation::updateEnemyPresentation()
{
    _timer++;

    // This loop updates the enemies sprite position by checking the updated logics position
    if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->getEnemyLogicVector().size() > 0) {
        for(unsigned int iter = 0; iter <unsigned(enemyPresentationVector.size()); iter++) {

            enemyPresentationVector[iter].updateEnemy(
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getXposition(),
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getYposition());

            if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector().size() > 0) {
                enemyPresentationVector[iter].updateEnemyBullet(
                    gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector()[0].getXposition(),
                    gameLogic_shared_pointer->getEnemyLogicVector()[iter]
                        .getEnemyBulletLogicVector()[0]
                        .getYposition());
            }
            // Checking if the enemy has gone out of scope and if so, it will recenter the enemy
            if(_timer % 125 == 0 && _timer > 0) {
                if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].isOutOfBounds() == true) {
                    gameLogic_shared_pointer->setEnemyBounds(false, iter);
                    gameLogic_shared_pointer->moveEnemyToCenter(iter);
                    enemyPresentationVector[iter].moveToCenter();
                }
            }
        }
    }
}

void GamePresentation::drawAllEnemies(RenderWindow& window)
{
    // drawing all the enemies
    gameLogic_shared_pointer->checkCollision();
    deleteDeadEnemies();
    deleteDeadEnemyBullets();
    if(enemyPresentationVector.size() > 0) {
        for(auto& iter : enemyPresentationVector) {
            iter.draw(window);
        }
    }
}

vector<EnemyPresentation> GamePresentation::getEnemyPresentationVector()
{
    return enemyPresentationVector;
}

void GamePresentation::deleteDeadEnemies()
{
    for(unsigned int iter = 0; iter < unsigned(enemyPresentationVector.size()); iter++) {
        // delete enemies when they die
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->getEnemyLogicVector().size() > 0 &&
            enemyPresentationVector.size() == gameLogic_shared_pointer->getEnemyLogicVector().size()) {
            if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].isAlive() == false) {
                enemyPresentationVector.erase(enemyPresentationVector.begin() + iter);
                gameLogic_shared_pointer->deleteEnemyLogic(iter);
                _enemiesKilled++;
            }
        }
    }
    for(unsigned int index = 0; index < unsigned(gameLogic_shared_pointer->getSatelliteLogicVector().size()); index++) {
        if(gameLogic_shared_pointer->getSatelliteLogicVector()[index].isAlive() == false) {
            _satellitesKilled++;
            gameLogic_shared_pointer->deleteSatelliteLogic(index);
            satellitePresentationVector.erase(satellitePresentationVector.begin() + index);
        }
    }
}

int GamePresentation::getEnemiesKilled()
{
    return _enemiesKilled;
}

void GamePresentation::deleteDeadEnemyBullets()
{
    for(unsigned int iter = 0; iter < unsigned(enemyPresentationVector.size()); iter++) {
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->getEnemyLogicVector().size() > 0) {
            if(enemyPresentationVector[iter].getEnemyBulletPresentationVector().size() > 0 &&
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector().size() > 0) {
                if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector()[0].isAlive() ==
                    false) {
                    if(enemyPresentationVector[iter].getEnemyBulletPresentationVector().size() > 0) {
                        enemyPresentationVector[iter].deleteEnemyBulletPresentation();
                        gameLogic_shared_pointer->clearEnemyBullet(iter);
                    }
                }
            }
        }
    }
}

void GamePresentation::createSatellitePresenetation()
{
    for(auto i = 0; i < 3; i++) {

        SatellitePresentation satellitePresentation;

        satellitePresentationVector.push_back(satellitePresentation);
    }
}

void GamePresentation::drawSatellites(RenderWindow& window)
{
    if(satellitePresentationVector.size() > 0 && gameLogic_shared_pointer->getSatelliteLogicVector().size() > 0) {
        for(unsigned int index = 0; index < unsigned(satellitePresentationVector.size()); index++) {
            satellitePresentationVector[index].draw(window,
                gameLogic_shared_pointer->getSatelliteLogicVector()[index].getXposition(),
                gameLogic_shared_pointer->getSatelliteLogicVector()[index].getYposition());
        }
    }
}

vector<SatellitePresentation> GamePresentation::getSatellitePresentationVector()
{
    return satellitePresentationVector;
}

void GamePresentation::createSatelliteBulletPresentation()
{
    for(unsigned int i = 0; i < unsigned(satellitePresentationVector.size()); i++) {
        EnemyBulletPresentation satelliteBulletPresentation(
            gameLogic_shared_pointer->getSatelliteLogicVector()[i].getXposition(),
            gameLogic_shared_pointer->getSatelliteLogicVector()[i].getYposition());
        satelliteBulletPresentationVector.push_back(satelliteBulletPresentation);
    }
}

void GamePresentation::drawSatelliteBullets(RenderWindow& window)
{
    for(unsigned int i = 0; i < unsigned(satelliteBulletPresentationVector.size()); i++) {
        gameLogic_shared_pointer->updateSatelliteBullets(i);
        satelliteBulletPresentationVector[i].draw(window);
        satelliteBulletPresentationVector[i].updateEnemyBullet(
            gameLogic_shared_pointer->getSatellietBulletLogicVector()[i].getXposition(),
            gameLogic_shared_pointer->getSatellietBulletLogicVector()[i].getYposition());
    }
}

void GamePresentation::updateLaserGeneratorPresentation()
{
    if(_laserGeneratorPresentation.size() > 0) {
        if(_laserGeneratorPresentation[0].getLaserGeneratorPresentationVector().size() > 0) {
            for(unsigned int i = 0; i < unsigned(_laserGeneratorPresentation[0].getLaserGeneratorPresentationVector().size()); i++) {
                _laserGeneratorPresentation[0].updateLaserGeneratorEnemy(i,
                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                        .getLaserGeneratorEnemyLogicVector()[i]
                        .getXposition(),
                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                        .getLaserGeneratorEnemyLogicVector()[i]
                        .getYposition());

                for(unsigned int i = 0; i < unsigned(_laserGeneratorPresentation[0].getLaserBulletPresentationVector().size()); i++) {
                    _laserGeneratorPresentation[0].updateLaserBulletPresentation(i,
                        gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                            .getLaserGeneratorBulletLogicVector()[i]
                            .getXposition(),
                        gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                            .getLaserGeneratorBulletLogicVector()[i]
                            .getYposition());
                }
            }
        }
    }
}

void GamePresentation::drawLaserGenerator(RenderWindow& window)
{
    if(_laserGeneratorPresentation.size() > 0) {
        _laserGeneratorPresentation[0].draw(window);
    }
}

void GamePresentation::createLaserGenerator()
{
    LaserGeneratorPresentation laserGeneratorPresentation;
    _laserGeneratorPresentation.push_back(laserGeneratorPresentation);
}

void GamePresentation::deleteLaserGenerator()
{
    bool isDead = false;
    if(_laserGeneratorPresentation.size() > 0) {
        for(auto i = 0; i < 2; i++) {
            if(gameLogic_shared_pointer->getlaserGeneratorLogic()[0].getLaserGeneratorEnemyLogicVector()[i].isAlive() ==
                false) {
                isDead = true;
            }
        }
    }
    if(isDead == true) {
        if(_laserGeneratorPresentation.size() > 0) {
            _laserGeneratorPresentation.clear();
            gameLogic_shared_pointer->deleteLaserGenerator();
        }
    }
}

void GamePresentation::createAsteroidPresentation()
{
    AsteroidPresentation asteroidPresentation;
    asteroidPresentationVector.push_back(asteroidPresentation);
}

void GamePresentation::updateAsteroidPresentation()
{

    if(asteroidPresentationVector.size() > 0) {
        for(unsigned int i = 0; i < asteroidPresentationVector.size(); i++) {
            asteroidPresentationVector[i].updateAsteroid(
                gameLogic_shared_pointer->getAsteroidLogicVector()[i].getXposition(),
                gameLogic_shared_pointer->getAsteroidLogicVector()[i].getYposition());
        }
    }
}

void GamePresentation::drawAsteroid(RenderWindow& window)
{
    if(asteroidPresentationVector.size() > 0) {
        for(auto& iter : asteroidPresentationVector) {
            iter.draw(window);
        }
    }
}

void GamePresentation::deleteOutofScopeAsteroidsPresentation()
{
    if(asteroidPresentationVector.size() > 0) {
        for(unsigned int i = 0; i < asteroidPresentationVector.size(); i++) {
            if(gameLogic_shared_pointer->getAsteroidLogicVector()[i].isOutOfBounds() == true ||
                gameLogic_shared_pointer->getAsteroidLogicVector()[i].isAlive() == false) {
                gameLogic_shared_pointer->deleteOutOfScopeAsteroids(i);
                asteroidPresentationVector.erase(asteroidPresentationVector.begin() + i);
            }
        }
    }
}

vector<LaserGeneratorPresentation> GamePresentation::getLaserGeneratorPresentation()
{
    return _laserGeneratorPresentation;
}

vector<AsteroidPresentation> GamePresentation::getAsteroidPresentationVector()
{
    return asteroidPresentationVector;
}