#include "GameLogic.h"

GameLogic::GameLogic()
{
    // PlayerLogic player();

   // CollisionDetection collisionDetection();

    LifeLogic lifeLogic(20, 570);
    _lifeLogic = lifeLogic;
}

void GameLogic::playerUpdate(Direction dir)
{
    player.playerMove(dir);
}

PlayerLogic GameLogic::getPlayerLogic()
{
    return player;
}

void GameLogic::updatePlayerLife()
{
    _playerLifesRemaining = _lifeLogic.getNumberOfLivesRemaining(player.getHealth());
    // std::cout<<_playerLifesRemaining<<std::endl;
}

int GameLogic::getPlayerLivesRemaining()
{
    return _playerLifesRemaining;
}

LifeLogic GameLogic::getPlayerLifeLogic()
{
    return _lifeLogic;
}

void GameLogic::createPlayerBullet()
{

    PlayerBullet playerBullet(player.getXposition(), player.getYposition(), player.getTheta(), _playerBulletType);

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

void GameLogic::setPlayerBulletType(int type)
{
    _playerBulletType = type;
}

int GameLogic::getPlayerBulletType()
{
    return _playerBulletType;
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
    if(enemyLogicVector.size() > 0) {
        for(auto& iter : enemyLogicVector) {
            iter.move();
        }
    }
}

void GameLogic::checkEnemyScope()
{
    if(enemyLogicVector.size() > 0) {
        for(auto& iter : enemyLogicVector) {
            if(iter.getXposition() < 0 || iter.getXposition() > GameXWindow || iter.getYposition() < 0 ||
                iter.getYposition() > GameYWindow) {
                iter.setOutofBounds(true);
            }
        }
    }
}
void GameLogic::checkCollision()
{

    if(enemyLogicVector.size() > 0) {
        for(auto index = 0; index < enemyLogicVector.size(); index++) {
            // Checking collision between player and enemy
            if(collisionDetection.didObjectsCollide(player, enemyLogicVector[index]) == true) {
                // std::cout <<"collision" << std::endl;
                enemyLogicVector[index].setLife(false);
            }

            if(enemyLogicVector[index].getEnemyBulletLogicVector().size() > 0) {
                if(collisionDetection.didObjectsCollide(
                       player, enemyLogicVector[index].getEnemyBulletLogicVector()[0]) == true) {

                     std::cout << "collision" << std::endl;

                    enemyLogicVector[index].setEnemyBulletLife(false);

                    player.reduceHealth(enemyLogicVector[index].getEnemyBulletLogicVector()[0].getDamage());
                }
            }

            // check collision between all player bullets and enemies
            for(auto& iter : playerBulletLogicVector) {
                if(collisionDetection.didObjectsCollide(iter, enemyLogicVector[index]) == true) {
                    // std::cout<<"collision"<<std::endl;
                    enemyLogicVector[index].reduceHealth(iter.getDamage());
                    iter.setLife(false);
                }
            }
        }
    }

    if(satelliteLogicVector.size() > 0) {
        for(auto& iter : satelliteLogicVector) {

            if(playerBulletLogicVector.size() > 0) {
                for(auto& iter1 : playerBulletLogicVector) {
                    if(collisionDetection.didObjectsCollide(iter, iter1)) {
                        iter1.setLife(false);
                        iter.decreaseHealth(iter1.getDamage());
                    }
                }
            }
        }
    }

    if(satelliteBulletLogic.size() > 0) {
        for(auto& iter : satelliteBulletLogic) {
            if(collisionDetection.didObjectsCollide(player, iter) == true) {
                iter.setLife(false);
                player.reduceHealth(iter.getDamage());
                // std::cout << player.getHealth() << std::endl;
            }
        }
    }

    if(_laserGeneratorLogic.size() > 0) {
        for(auto& iter : _laserGeneratorLogic[0]._laserGeneratorEnemyLogicVector) {

            if(playerBulletLogicVector.size() > 0) {
                for(auto& iter1 : playerBulletLogicVector) {
                    if(collisionDetection.didObjectsCollide(iter, iter1) == true) {
                        iter1.setLife(false);
                        iter.reduceHealth(iter1.getDamage());
                    }
                }
            }

            if(collisionDetection.didObjectsCollide(player, iter) == true) {
                player.reduceHealth(100);
            }
        }

        for(auto& iter2 : _laserGeneratorLogic[0]._laserGeneratorEnemyBulletLogicVector) {
            if(collisionDetection.didObjectsCollide(player, iter2) == true) {
                player.reduceHealth(iter2.getDamage());
            }
        }
    }
}

void GameLogic::createSatellites()
{
    for(auto i = 0; i < 3; i++) {
        SatelliteLogic satelliteLogic(player.getXposition() - radius * 0.6 * (cos(player.getTheta())) + 30 * i,
            player.getYposition() - radius * 0.6 * (sin(player.getTheta())) + 30 * i, 0.05);
        std::cout << player.getXposition() - radius * 0.5 * (cos(player.getTheta())) + 30 * i << "   "
                  << player.getYposition() - radius * 0.5 * (sin(player.getTheta())) + 30 * i << std::endl;
        satelliteLogicVector.push_back(satelliteLogic);
    }
}

void GameLogic::updateSatelliteLogic()
{
    if(satelliteLogicVector.size() > 0) {
        for(auto& iter : satelliteLogicVector) {
            iter.move();
        }
    }
}

void GameLogic::fireSatelliteBulletLogic()
{
    if(satelliteLogicVector.size() > 0) {
        for(auto& iter : satelliteLogicVector) {
            EnemyBulletLogic satelliteBullet(iter.getXposition(), iter.getYposition(), player.getTheta());
            satelliteBulletLogic.push_back(satelliteBullet);
        }
    }
}

void GameLogic::checkSatelliteBulletScope()
{
    for(auto& iter : satelliteBulletLogic) {
        if(iter.getXposition() < 0 || iter.getXposition() > GameXWindow || iter.getYposition() < 0 ||
            iter.getYposition() > GameYWindow) {
            //  std::cout<<"delete bullet"<<std::endl;
            iter.setLife(false);
        }
    }
}

void GameLogic::updateLaserLogic()
{
    checkLaserGeneratorScope();
    
    if(_laserGeneratorLogic.size() > 0) {
        _laserGeneratorLogic[0].move();
    }

    // std::cout<<_laserGeneratorLogic._laserGeneratorEnemyBulletLogicVector[2].getXposition()<< std::endl;
}

void GameLogic::createLaserGeneratorLogic()
{
    LaserGeneratorLogic LaserGeneratorLogic;
    _laserGeneratorLogic.push_back(LaserGeneratorLogic);
  
}

void GameLogic::checkLaserGeneratorScope()
{
      
    bool isOutOfScope = false;
    if(_laserGeneratorLogic.size() > 0) {
        for(auto& iter : _laserGeneratorLogic[0]._laserGeneratorEnemyLogicVector) {
            if(iter.getXposition() < 0 || iter.getXposition() > GameXWindow || iter.getYposition() < 0 ||
                iter.getYposition() > GameYWindow){
                    isOutOfScope = true;
                }
        }
    }
    
    if (isOutOfScope == true){
        _laserGeneratorLogic[0]._laserGeneratorEnemyLogicVector[0].setLife(false);
        
    }
}


void GameLogic::createAsteroid(){
    AsteroidLogic asteroidLogic(player.getTheta());
    asteroidLogicVector.push_back(asteroidLogic);
}


void GameLogic::updateAsteroidLogic(){
    if(asteroidLogicVector.size() > 0){
        asteroidLogicVector[0].move();
    }
}

vector<LaserGeneratorLogic> GameLogic::getlaserGeneratorLogic(){
    return _laserGeneratorLogic;
}

void GameLogic::deleteLaserGenerator(){
    
    
    if(_laserGeneratorLogic.size() > 0){
    _laserGeneratorLogic.clear();
    }
    
}


void GameLogic::deletePlayerBullet(int index){
    playerBulletLogicVector.erase(playerBulletLogicVector.begin() + index);
}

vector<EnemyLogic> GameLogic::getEnemyLogicVector(){
    return enemyLogicVector;
}

void GameLogic::deleteEnemyLogic(int index){
    enemyLogicVector.erase(enemyLogicVector.begin() + index);
}

void GameLogic::setEnemyBounds(bool isInBounds, int index){
    enemyLogicVector[index].setOutofBounds(isInBounds);
}

void GameLogic::moveEnemyToCenter(int index){
    enemyLogicVector[index].moveToCenter(CenterXGameWindow, CenterYGameWindow, player.getTheta());
}

void GameLogic::clearEnemyBullet(int index){
    enemyLogicVector[index].clearEnemyBulletVector();
}

 vector<SatelliteLogic> GameLogic::getSatelliteLogicVector(){
     return satelliteLogicVector;
 }
 
 void GameLogic::deleteSatelliteLogic(int index){
     satelliteLogicVector.erase(satelliteLogicVector.begin() + index);
 }
 
 vector<EnemyBulletLogic> GameLogic::getSatellietBulletLogicVector(){
     return satelliteBulletLogic;
 }
 
 void GameLogic::deleteSatelliteBulletLogic(int index){
     satelliteBulletLogic.erase(satelliteBulletLogic.begin() + index);
 }
 
 void GameLogic::updateSatelliteBullets(int index){
     
     satelliteBulletLogic[index].move();
     
 }
 
 vector<AsteroidLogic> GameLogic::getAsteroidLogicVector(){
     return asteroidLogicVector;
 }