#include "GamePresentation.h"

GamePresentation::GamePresentation()
{
    PlayerPresentation _playerPresentation();

    gameLogic_shared_pointer = make_shared<GameLogic>();
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
}

void GamePresentation::createPlayerBulletPresentation()
{
    PlayerBulletPresentation playerBulletPresentation((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),
        (gameLogic_shared_pointer->getPlayerLogic()).getYposition());
    playerBulletPresentationVector.push_back(playerBulletPresentation);
}

void GamePresentation::upDatePlayerBulletPresentation()
{
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
    if (enemyPresentationVector.size()>0 && gameLogic_shared_pointer->enemyLogicVector.size()>0){
    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

        enemyPresentationVector[iter].updateEnemy(gameLogic_shared_pointer->enemyLogicVector[iter].getXposition(),
            gameLogic_shared_pointer->enemyLogicVector[iter].getYposition());

        enemyPresentationVector[iter]._circle.setPosition(
            gameLogic_shared_pointer->enemyLogicVector[iter].getCenterXPosition(),
            gameLogic_shared_pointer->enemyLogicVector[iter].getCenterYPosition());

        if(gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.size() > 0) {
            enemyPresentationVector[iter].updateEnemyBullet(
                gameLogic_shared_pointer->enemyLogicVector[iter].getEnemyBulletLogicVector()[0].getXposition(),
                gameLogic_shared_pointer->enemyLogicVector[iter].getEnemyBulletLogicVector()[0].getYposition());
        }

        // Checking if the enemy has gone out of scope and if so, it will recenter the enemy
        if(_timer % 55 == 0) {
            if(gameLogic_shared_pointer->enemyLogicVector[iter].isOutOfBounds() == true) {

                gameLogic_shared_pointer->enemyLogicVector[iter].setOutofBounds(false);
                (gameLogic_shared_pointer->enemyLogicVector[iter])
                    .moveToCenter(
                        CenterXGameWindow, CenterYGameWindow, gameLogic_shared_pointer->getPlayerLogic().getTheta());
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
        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->enemyLogicVector.size() > 0) {

            if(gameLogic_shared_pointer->enemyLogicVector[iter].isAlive() == false) {

                enemyPresentationVector.erase(enemyPresentationVector.begin() + iter);

                (gameLogic_shared_pointer->enemyLogicVector)
                    .erase((gameLogic_shared_pointer->enemyLogicVector).begin() + iter);
                std::cout << "dead" << std::endl;
            }

            // delete bullets when they hit the player
            if(enemyPresentationVector.size()>0){
            if(enemyPresentationVector[iter]._enemyBulletPresentationVector.size() > 0 &&
                gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.size() > 0) {
                    
                if(gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector[0].isAlive() == false) {
                    enemyPresentationVector[iter]._enemyBulletPresentationVector.clear();
                    gameLogic_shared_pointer->enemyLogicVector[iter].enemyBulletLogicVector.clear();
                }
                }
            }
        }
    }
}
