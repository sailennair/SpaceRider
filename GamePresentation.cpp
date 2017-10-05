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
    for(auto iter = 0; iter < playerBulletPresentationVector.size(); iter++) {

        playerBulletPresentationVector[iter].updateBullet(
            gameLogic_shared_pointer->getPlayerLogicBullets()[iter].getXposition(),
            gameLogic_shared_pointer->getPlayerLogicBullets()[iter].getYposition());
    }
}

void GamePresentation::drawAllBullets(RenderWindow& window)
{
    deleteOutofScopeBullets();
    for(auto iter = 0; iter < playerBulletPresentationVector.size(); iter++) {

        playerBulletPresentationVector[iter].draw(window);
    }
}

void GamePresentation::deleteOutofScopeBullets()
{

    for(auto iter = 0; iter < playerBulletPresentationVector.size(); iter++) {

        std::cout << gameLogic_shared_pointer->getPlayerLogicBullets()[iter].isAlive() << std::endl;

        if(playerBulletPresentationVector.size() > 0 && gameLogic_shared_pointer->getPlayerLogicBullets().size() > 0) {

            if(gameLogic_shared_pointer->getPlayerLogicBullets()[iter].isAlive() == false) {

                playerBulletPresentationVector.erase(playerBulletPresentationVector.begin() + iter);

                (gameLogic_shared_pointer->playerBulletLogicVector)
                    .erase((gameLogic_shared_pointer->playerBulletLogicVector).begin() + iter);
                std::cout << "deleted" << std::endl;
            }
        }
    }
}

void GamePresentation::createEnemyPresentationObject(){
    
    EnemyPresentation enemyPresentation;
    enemyPresentationVector.push_back(enemyPresentation);
    
}

void GamePresentation::updateEnemyPresentation(){
    
    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

        enemyPresentationVector[iter].updateEnemy(
            gameLogic_shared_pointer->enemyLogicVector[iter].getXposition(),
            gameLogic_shared_pointer->enemyLogicVector[iter].getYposition());
            
            enemyPresentationVector[iter].updateEnemyBullet(gameLogic_shared_pointer->enemyLogicVector[iter]._enemyBulletLogic.getXposition(),
            gameLogic_shared_pointer->enemyLogicVector[iter]._enemyBulletLogic.getYposition());
            
           std::cout<<gameLogic_shared_pointer->enemyLogicVector[iter]._enemyBulletLogic.getXposition()<<"   "<<
            gameLogic_shared_pointer->enemyLogicVector[iter]._enemyBulletLogic.getYposition()<<std::endl;
    }
}


void GamePresentation::drawAllEnemies(RenderWindow& window){
    //drawing all the enemies
    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

        enemyPresentationVector[iter].draw(window);
    }
}