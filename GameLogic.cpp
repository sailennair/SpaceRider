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

    PlayerBullet playerBullet(player.getXposition() + 40, player.getYposition() + 40, player.getTheta());

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