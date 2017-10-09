#include "GamePresentation.h"

GamePresentation::GamePresentation()
{
    PlayerPresentation _playerPresentation();

    gameLogic_shared_pointer = make_shared<GameLogic>();
    Score _gameScore();
}

void GamePresentation::upDatePlayerPosition()
{

    _playerPresentation._Player.setPosition((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),
        (gameLogic_shared_pointer->getPlayerLogic()).getYposition());
        
        
        
        _playerPresentation._rect.setPosition((gameLogic_shared_pointer->getPlayerLogic()).getCenterXPosition(),
        (gameLogic_shared_pointer->getPlayerLogic()).getCenterYPosition());

//_playerPresentation._rect.setPosition((gameLogic_shared_pointer->getPlayerLogic()).getXposition(),
//        (gameLogic_shared_pointer->getPlayerLogic()).getYposition());


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
    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

        enemyPresentationVector[iter].updateEnemy(gameLogic_shared_pointer->enemyLogicVector[iter].getXposition(),
            gameLogic_shared_pointer->enemyLogicVector[iter].getYposition());
            
            
            enemyPresentationVector[iter]._circle.setPosition(gameLogic_shared_pointer->enemyLogicVector[iter].getCenterXPosition(),
            gameLogic_shared_pointer->enemyLogicVector[iter].getCenterYPosition());

        enemyPresentationVector[iter].updateEnemyBullet(
            gameLogic_shared_pointer->enemyLogicVector[iter]._enemyBulletLogic.getXposition(),
            gameLogic_shared_pointer->enemyLogicVector[iter]._enemyBulletLogic.getYposition());

        // Checking if the enemy has gone out of scope and if so, it will recenter the enemy
        if(_timer % 55 == 0) {
            if(gameLogic_shared_pointer->enemyLogicVector[iter].isOutOfBounds() == true ) {
               // &&
               // gameLogic_shared_pointer->enemyLogicVector.size() == 5

                gameLogic_shared_pointer->enemyLogicVector[iter].setOutofBounds(false);
                (gameLogic_shared_pointer->enemyLogicVector[iter])
                    .moveToCenter(
                        CenterXGameWindow, CenterYGameWindow, gameLogic_shared_pointer->getPlayerLogic().getTheta());
                //  std::cout << "center" << std::endl;
            }
        }
    }
}

void GamePresentation::drawAllEnemies(RenderWindow& window)
{
    // drawing all the enemies
    //    int i = 0;
    gameLogic_shared_pointer->checkCollision();
    deleteDeadEnemies();

 //   std::cout << enemyPresentationVector.size() << "    " << gameLogic_shared_pointer->enemyLogicVector.size()
    //          << std::endl;

    for(auto& iter : enemyPresentationVector) {
        //        if (gameLogic_shared_pointer->enemyLogicVector[i].isAlive() == true){
        iter.draw(window);
        //        std::cout<< gameLogic_shared_pointer->enemyLogicVector[i].isAlive() <<std::endl;
        //        }
        //        i++;
    }
}

vector<EnemyPresentation> GamePresentation::getEnemyPresentationVector()
{
    return enemyPresentationVector;
}

void GamePresentation::deleteDeadEnemies()
{

    for(auto iter = 0; iter < enemyPresentationVector.size(); iter++) {

        if(enemyPresentationVector.size() > 0 && gameLogic_shared_pointer->enemyLogicVector.size() > 0) {

            if(gameLogic_shared_pointer->enemyLogicVector[iter].isAlive() == false) {

                enemyPresentationVector.erase(enemyPresentationVector.begin() + iter);

                (gameLogic_shared_pointer->enemyLogicVector)
                    .erase((gameLogic_shared_pointer->enemyLogicVector).begin() + iter);
                    
                    _gameScore.setScorePoints(10, "William");
                    
            }
        }
    }
}