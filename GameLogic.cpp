#include "GameLogic.h"

GameLogic::GameLogic()
{
    PlayerLogic player();
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
    for(auto iter = 0; iter < playerBulletLogicVector.size(); iter++) {
        if(playerBulletLogicVector[iter].getXposition() < CenterXGameWindow + 20 &&
            playerBulletLogicVector[iter].getXposition() > CenterXGameWindow - 20 &&
            playerBulletLogicVector[iter].getYposition() > CenterYGameWindow - 20 &&
            playerBulletLogicVector[iter].getYposition() < CenterYGameWindow + 20) {

            playerBulletLogicVector[iter].setLife(false);
        }
    }
}

void GameLogic::createEnemyLogicObject(){
    EnemyLogic enemyLogic(CenterXGameWindow,CenterYGameWindow, player.getTheta());
    enemyLogicVector.push_back(enemyLogic);
}

void GameLogic::updateEnemyLogic(){
    for(auto& iter: enemyLogicVector){
        iter.move();
    }
}
