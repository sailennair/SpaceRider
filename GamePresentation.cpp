#include "GamePresentation.h"

GamePresentation::GamePresentation()
{
    PlayerPresentation _playerPresentation();

    gameLogic_shared_pointer = make_shared<GameLogic>();
    LifePresentation _lifePresentation();
}

void GamePresentation::upDatePlayerPosition()
{

    _playerPresentation._Player.setPosition((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),
        (gameLogic_shared_pointer->getPlayerLogic()).getYposition());

    //    _playerPresentation._rect.setPosition((gameLogic_shared_pointer->getPlayerLogic()).getCenterXPosition(),
    //        (gameLogic_shared_pointer->getPlayerLogic()).getCenterYPosition());

    _playerPresentation._Player.rotate((gameLogic_shared_pointer->getPlayerLogic()).getAngleofRotation());
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

    // Drawing the lifes at the bottom of the screen

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

    if(_satellitesKilled >= 3 && _satellitesKilled % 3 == 0) {
        gameLogic_shared_pointer->setPlayerBulletType(2);
    }
    for(auto index = 0; index < playerBulletPresentationVector.size(); index++) {

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
    for(auto iter = 0; iter < playerBulletPresentationVector.size(); iter++) {

        if(playerBulletPresentationVector.size() > 0 && gameLogic_shared_pointer->getPlayerLogicBullets().size() > 0) {

            if(gameLogic_shared_pointer->getPlayerLogicBullets()[iter].isAlive() == false) {

                playerBulletPresentationVector.erase(playerBulletPresentationVector.begin() + iter);

                //                (gameLogic_shared_pointer->playerBulletLogicVector)
                //                    .erase((gameLogic_shared_pointer->playerBulletLogicVector).begin() + iter);

                gameLogic_shared_pointer->deletePlayerBullet(iter);
            }
        }
    }

    for(auto index = 0; index < satelliteBulletPresentationVector.size(); index++) {
        if(satelliteBulletPresentationVector.size() > 0) {
            if(gameLogic_shared_pointer->getSatellietBulletLogicVector()[index].isAlive() == false) {

                gameLogic_shared_pointer->deleteSatelliteBulletLogic(index);

                //                gameLogic_shared_pointer->satelliteBulletLogic.erase(
                //                    gameLogic_shared_pointer->satelliteBulletLogic.begin() + index);

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
        for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

            enemyPresentationVector[iter].updateEnemy(
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getXposition(),
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getYposition());
            // std::cout << "one" << std::endl;
            enemyPresentationVector[iter]._circle.setPosition(
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getCenterXPosition(),
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getCenterYPosition());
            // std::cout << "two" << std::endl;
            if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector().size() > 0) {
                enemyPresentationVector[iter].updateEnemyBullet(
                    gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector()[0].getXposition(),
                    gameLogic_shared_pointer->getEnemyLogicVector()[iter]
                        .getEnemyBulletLogicVector()[0]
                        .getYposition());
                // std::cout << "three" << std::endl;
            }

            // Checking if the enemy has gone out of scope and if so, it will recenter the enemy
            if(_timer % 50 == 0 && _timer > 0) {
                if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].isOutOfBounds() == true) {

                    gameLogic_shared_pointer->setEnemyBounds(false, iter);

                    // std::cout << gameLogic_shared_pointer->getEnemyLogicVector()[iter].isOutOfBounds() << std::endl;

                    gameLogic_shared_pointer->moveEnemyToCenter(iter);

                    //                    (gameLogic_shared_pointer->getEnemyLogicVector()[iter])
                    //                        .moveToCenter(CenterXGameWindow, CenterYGameWindow,
                    //                            gameLogic_shared_pointer->getPlayerLogic().getTheta());

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
    // std::cout << "notyet" << std::endl;
    deleteDeadEnemies();
    // std::cout << "crashing" << std::endl;
    deleteDeadEnemyBullets();
    // std::cout << "Bullets" << std::endl;
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

    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {
        // delete enemies when they die
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->getEnemyLogicVector().size() > 0 &&
            enemyPresentationVector.size() == gameLogic_shared_pointer->getEnemyLogicVector().size()) {
            //   std::cout << "one" << std::endl;
            if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].isAlive() == false) {
                //   std::cout << "two" << std::endl;
                enemyPresentationVector.erase(enemyPresentationVector.begin() + iter);

                //                (gameLogic_shared_pointer->enemyLogicVector)
                //                    .erase((gameLogic_shared_pointer->enemyLogicVector).begin() + iter);

                gameLogic_shared_pointer->deleteEnemyLogic(iter);
                //  std::cout << "three" << std::endl;
                // std::cout << "dead" << std::endl;
            }

            // delete bullets when they hit the player
            //            if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->enemyLogicVector.size() >
            //            0) {
            //                // std::cout << "one" << std::endl;
            //                if(enemyPresentationVector[iter]._enemyBulletPresentationVector.size() > 0 &&
            //                    gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.size() > 0) {
            //                    //  std::cout << "two" << std::endl;
            //                    if(gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector[0].isAlive()
            //                    == false) {
            //                        //  std::cout << "yes" << std::endl;
            //                        if(enemyPresentationVector[iter]._enemyBulletPresentationVector.size() > 0) {
            //                            enemyPresentationVector[iter]._enemyBulletPresentationVector.clear();
            //                            gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.clear();
            //                        }
            //                    }
            //                }
            //            }
        }
    }

    for(auto index = 0; index < gameLogic_shared_pointer->getSatelliteLogicVector().size(); index++) {
        if(gameLogic_shared_pointer->getSatelliteLogicVector()[index].isAlive() == false) {
            _satellitesKilled++;

            gameLogic_shared_pointer->deleteSatelliteLogic(index);

            //            gameLogic_shared_pointer->satelliteLogicVector.erase(
            //                gameLogic_shared_pointer->satelliteLogicVector.begin() + index);
            satellitePresentationVector.erase(satellitePresentationVector.begin() + index);

            // if(gameLogic_shared_pointer->satelliteBulletLogic > 0)
            //            gameLogic_shared_pointer->satelliteBulletLogic.erase(gameLogic_shared_pointer->satelliteBulletLogic.begin()
            //            + index);
            //            satelliteBulletPresentationVector.erase(satelliteBulletPresentationVector.begin() + index);
        }
    }
}

void GamePresentation::deleteDeadEnemyBullets()
{

    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {
        // delete bullets when they hit the player
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->getEnemyLogicVector().size() > 0) {
            // std::cout<<"one"<<std::endl;
            if(enemyPresentationVector[iter].getEnemyBulletPresentationVector().size() > 0 &&
                gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector().size() > 0) {

                if(gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector()[0].isAlive() ==
                    false) {
                    if(enemyPresentationVector[iter].getEnemyBulletPresentationVector().size() > 0) {
                        enemyPresentationVector[iter].deleteEnemyBulletPresentation();
                        gameLogic_shared_pointer->clearEnemyBullet(iter);

                        // std::cout<<gameLogic_shared_pointer->getEnemyLogicVector()[iter].getEnemyBulletLogicVector().size()<<std::endl;
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
        for(auto index = 0; index < satellitePresentationVector.size(); index++) {

            satellitePresentationVector[index]._rect.setPosition(
                gameLogic_shared_pointer->getSatelliteLogicVector()[index].getCenterXPosition(),
                gameLogic_shared_pointer->getSatelliteLogicVector()[index].getCenterYPosition());

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
    for(auto i = 0; i < satellitePresentationVector.size(); i++) {
        EnemyBulletPresentation satelliteBulletPresentation(
            gameLogic_shared_pointer->getSatelliteLogicVector()[i].getXposition(),
            gameLogic_shared_pointer->getSatelliteLogicVector()[i].getYposition());
        satelliteBulletPresentationVector.push_back(satelliteBulletPresentation);
    }
}

void GamePresentation::drawSatelliteBullets(RenderWindow& window)
{
    for(auto i = 0; i < satelliteBulletPresentationVector.size(); i++) {

        gameLogic_shared_pointer->updateSatelliteBullets(i);

        // std::cout << satelliteBulletPresentationVector.size() << std::endl;
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
            for(auto i = 0; i < _laserGeneratorPresentation[0].getLaserGeneratorPresentationVector().size(); i++) {

                _laserGeneratorPresentation[0].updateLaserGeneratorEnemy(i,
                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                        .getLaserGeneratorEnemyLogicVector()[i]
                        .getXposition(),
                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                        .getLaserGeneratorEnemyLogicVector()[i]
                        .getYposition());

                //                _laserGeneratorPresentation[0].laserGeneratorPresentationVector[i].updateEnemy(
                //                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                //                        .getLaserGeneratorEnemyLogicVector()[i]
                //                        .getXposition(),
                //                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                //                        .getLaserGeneratorEnemyLogicVector()[i]
                //                        .getYposition());
            }

            //*****
            for(auto i = 0; i < _laserGeneratorPresentation[0].getLaserBulletPresentationVector().size(); i++) {

                _laserGeneratorPresentation[0].updateLaserBulletPresentation(i,
                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                        .getLaserGeneratorBulletLogicVector()[i]
                        .getXposition(),
                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                        .getLaserGeneratorBulletLogicVector()[i]
                        .getYposition());

                //                _laserGeneratorPresentation[0].laserBulletPresentationVector[i].updateEnemyBullet(
                //
                //                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                //                        .getLaserGeneratorBulletLogicVector()[i]
                //                        .getXposition(),
                //                    gameLogic_shared_pointer->getlaserGeneratorLogic()[0]
                //                        .getLaserGeneratorBulletLogicVector()[i]
                //                        .getYposition());
                // std::cout << "one" << std::endl;
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
            // gameLogic_shared_pointer->_laserGeneratorLogic.clear();
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
        for(auto i = 0; i < asteroidPresentationVector.size(); i++) {
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
        for(auto i = 0; i < asteroidPresentationVector.size(); i++) {
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