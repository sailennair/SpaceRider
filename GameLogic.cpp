#include "GameLogic.h"

GameLogic::GameLogic()
{
    PlayerLogic player();
    
    CollisionDetection collisionDetection();
}

void GameLogic::playerUpdate(Direction dir)
{
    player.playerMove(dir);
}

PlayerLogic GameLogic::getPlayerLogic()
{
    return player;
}
void GameLogic::createPlayerBullet()
{

    PlayerBullet playerBullet(player.getXposition(), player.getYposition(), player.getTheta());

    playerBulletLogicVector.push_back(playerBullet);
}

vector<PlayerBullet> GameLogic::getPlayerLogicBullets()
{
    return playerBulletLogicVector;
}

void GameLogic::playerBulletUpdate()
{
    for(auto iter = 0; iter < playerBulletLogicVector.size(); iter++) {
        playerBulletLogicVector[iter].fire();
    }
}

void GameLogic::checkBulletScope()
{
    for(auto& iter : playerBulletLogicVector) {
        if(iter.getXposition() < CenterXGameWindow + 20 && iter.getXposition() > CenterXGameWindow - 20 &&
            iter.getYposition() > CenterYGameWindow - 20 && iter.getYposition() < CenterYGameWindow + 20) {
            iter.setLife(false);
        }
    }
}

void GameLogic::createEnemyLogicObject()
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, player.getTheta());
    enemyLogicVector.push_back(enemyLogic);
}

void GameLogic::updateEnemyLogic()
{
    for(auto& iter : enemyLogicVector) {
        iter.move();
        
    }
    
//    for (auto index = 0; index < enemyLogicVector.size(); index++){
//        if( collisionDetection.didObjectsCollide(player, enemyLogicVector[index]) == true){
//            std::cout <<"collision" << std:: endl;
//             std::cout<<  enemyLogicVector[index].isAlive() << std::endl;
//            enemyLogicVector[index].setLife(false); 
//
//std::cout<<  enemyLogicVector[index].isAlive() << std::endl;
//            
//        }
        
      //  std::cout<<  enemyLogicVector[index].isAlive() << std::endl;
    //}
    
    
    
   
}

void GameLogic::checkEnemyScope()
{
    for(auto& iter : enemyLogicVector) {
        if(iter.getXposition() < 0 || iter.getXposition() > GameXWindow || iter.getYposition() < 0 ||
            iter.getYposition() > GameYWindow) {
            iter.setOutofBounds(true);
        }
    }
    
}
void GameLogic::checkCollision(){
    
    for (auto index = 0; index < enemyLogicVector.size(); index++){
        //Checking collision between player and enemy
        if( collisionDetection.didObjectsCollide(player, enemyLogicVector[index]) == true){
            std::cout <<"collision" << std::endl;
            enemyLogicVector[index].setLife(false); 
        }
        
        //check collision between all player bullets and enemies
        for(auto& iter: playerBulletLogicVector){
            if(collisionDetection.didObjectsCollide(iter,enemyLogicVector[index]) == true){
                std::cout <<"collision" << std::endl;
                enemyLogicVector[index].reduceHealth(iter.getDamage());
                iter.setLife(false);
            }
        }
        
        
}



}

