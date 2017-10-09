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

void GamePresentation::renderSprite(RenderWindow& window)
{

    _playerPresentation.draw(window);
    
    //Drawing the lifes at the bottom of the screen
    
    _lifePresentation.draw(window, gameLogic_shared_pointer->getPlayerLifeLogic().getXpos(),  gameLogic_shared_pointer->getPlayerLifeLogic().getYpos());
    
  
}

void GamePresentation::setPlayerLifeCount(){
    
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
    
    if(_satellitesKilled >= 3 && _satellitesKilled%3 == 0){
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

                (gameLogic_shared_pointer->playerBulletLogicVector)
                    .erase((gameLogic_shared_pointer->playerBulletLogicVector).begin() + iter);
            }
        }
    }

    for(auto index = 0; index < satelliteBulletPresentationVector.size(); index++) {
        if(satelliteBulletPresentationVector.size() > 0) {
            if(gameLogic_shared_pointer->satelliteBulletLogic[index].isAlive() == false) {
                
                gameLogic_shared_pointer->satelliteBulletLogic.erase(
                    gameLogic_shared_pointer->satelliteBulletLogic.begin() + index);
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
    if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->enemyLogicVector.size() > 0) {
        for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

            enemyPresentationVector[iter].updateEnemy(gameLogic_shared_pointer->enemyLogicVector[iter].getXposition(),
                gameLogic_shared_pointer->enemyLogicVector[iter].getYposition());
            // std::cout << "one" << std::endl;
            enemyPresentationVector[iter]._circle.setPosition(
                gameLogic_shared_pointer->enemyLogicVector[iter].getCenterXPosition(),
                gameLogic_shared_pointer->enemyLogicVector[iter].getCenterYPosition());
            // std::cout << "two" << std::endl;
            if(gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.size() > 0) {
                enemyPresentationVector[iter].updateEnemyBullet(
                    gameLogic_shared_pointer->enemyLogicVector[iter].getEnemyBulletLogicVector()[0].getXposition(),
                    gameLogic_shared_pointer->enemyLogicVector[iter].getEnemyBulletLogicVector()[0].getYposition());
                // std::cout << "three" << std::endl;
            }

            // Checking if the enemy has gone out of scope and if so, it will recenter the enemy
            if(_timer % 1000 == 0) {
                if(gameLogic_shared_pointer->enemyLogicVector[iter].isOutOfBounds() == true) {

                    gameLogic_shared_pointer->enemyLogicVector[iter].setOutofBounds(false);
                    (gameLogic_shared_pointer->enemyLogicVector[iter])
                        .moveToCenter(CenterXGameWindow, CenterYGameWindow,
                            gameLogic_shared_pointer->getPlayerLogic().getTheta());
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
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->enemyLogicVector.size() > 0 &&
            enemyPresentationVector.size() == gameLogic_shared_pointer->enemyLogicVector.size()) {
         //   std::cout << "one" << std::endl;
            if(gameLogic_shared_pointer->enemyLogicVector[iter].isAlive() == false) {
             //   std::cout << "two" << std::endl;
                enemyPresentationVector.erase(enemyPresentationVector.begin() + iter);

                (gameLogic_shared_pointer->enemyLogicVector)
                    .erase((gameLogic_shared_pointer->enemyLogicVector).begin() + iter);
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

    for(auto index = 0; index < gameLogic_shared_pointer->satelliteLogicVector.size(); index++) {
        if(gameLogic_shared_pointer->satelliteLogicVector[index].isAlive() == false) {
            _satellitesKilled++;
            gameLogic_shared_pointer->satelliteLogicVector.erase(
                gameLogic_shared_pointer->satelliteLogicVector.begin() + index);
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
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->enemyLogicVector.size() > 0) {

            if(enemyPresentationVector[iter]._enemyBulletPresentationVector.size() > 0 &&
                gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.size() > 0) {

                if(gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector[0].isAlive() == false) {

                    if(enemyPresentationVector[iter]._enemyBulletPresentationVector.size() > 0) {

                        enemyPresentationVector[iter]._enemyBulletPresentationVector.clear();
                        gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.clear();
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
    if(satellitePresentationVector.size() > 0 && gameLogic_shared_pointer->satelliteLogicVector.size() > 0) {
        for(auto index = 0; index < satellitePresentationVector.size(); index++) {

            satellitePresentationVector[index]._rect.setPosition(
                gameLogic_shared_pointer->satelliteLogicVector[index].getCenterXPosition(),
                gameLogic_shared_pointer->satelliteLogicVector[index].getCenterYPosition());

            satellitePresentationVector[index].draw(window,
                gameLogic_shared_pointer->satelliteLogicVector[index].getXposition(),
                gameLogic_shared_pointer->satelliteLogicVector[index].getYposition());
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
            gameLogic_shared_pointer->satelliteLogicVector[i].getXposition(),
            gameLogic_shared_pointer->satelliteLogicVector[i].getYposition());
        satelliteBulletPresentationVector.push_back(satelliteBulletPresentation);
    }
}

void GamePresentation::drawSatelliteBullets(RenderWindow& window)
{
    for(auto i = 0; i < satelliteBulletPresentationVector.size(); i++) {
        gameLogic_shared_pointer->satelliteBulletLogic[i].move();

        //std::cout << satelliteBulletPresentationVector.size() << std::endl;
        satelliteBulletPresentationVector[i].draw(window);

        satelliteBulletPresentationVector[i].updateEnemyBullet(
            gameLogic_shared_pointer->satelliteBulletLogic[i].getXposition(),
            gameLogic_shared_pointer->satelliteBulletLogic[i].getYposition());
    }
}
