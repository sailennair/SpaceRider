#include "GameLogic.h"

GameLogic::GameLogic()
{
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

std::vector<PlayerBullet> GameLogic::getPlayerLogicBullets()
{
    return playerBulletLogicVector;
}

void GameLogic::playerBulletUpdate()
{
    for(unsigned int iter = 0; iter < playerBulletLogicVector.size(); iter++) {
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
    int bulletCenterTarget = 20;
    for(auto& iter : playerBulletLogicVector) {
        if(iter.getXposition() < CenterXGameWindow + bulletCenterTarget &&
            iter.getXposition() > CenterXGameWindow - bulletCenterTarget &&
            iter.getYposition() > CenterYGameWindow - bulletCenterTarget &&
            iter.getYposition() < CenterYGameWindow + bulletCenterTarget) {
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

bool GameLogic::checkPlayerLifeDead()
{
    if(_currentLife > getPlayerLivesRemaining()) {
        player.playerRestart();
        _currentLife = getPlayerLivesRemaining();
        return true;
    } else {
        return false;
    }
}

bool GameLogic::isPlayerDead()
{
    if(getPlayerLivesRemaining() <= 0) {
        return true;
    } else {
        return false;
    }
}
void GameLogic::checkCollision()
{

    if(enemyLogicVector.size() > 0) {
        // Checking collision between player and enemy
        for(unsigned int index = 0; index < enemyLogicVector.size(); index++) {
            if(collisionDetection.didObjectsCollide(player, enemyLogicVector[index]) == true) {
                enemyLogicVector[index].setLife(false);
                player.reduceHealth(20);
            }
            if(enemyLogicVector[index].getEnemyBulletLogicVector().size() > 0) {
                if(collisionDetection.didObjectsCollide(
                       player, enemyLogicVector[index].getEnemyBulletLogicVector()[0]) == true) {
                    enemyLogicVector[index].setEnemyBulletLife(false);
                    player.reduceHealth(enemyLogicVector[index].getEnemyBulletLogicVector()[0].getDamage());
                }
            }
            for(auto& iter : playerBulletLogicVector) {
                if(collisionDetection.didObjectsCollide(iter, enemyLogicVector[index]) == true) {
                    enemyLogicVector[index].reduceHealth(iter.getDamage());
                    iter.setLife(false);
                }
            }
        }
    }

    if(satelliteLogicVector.size() > 0 && playerBulletLogicVector.size() > 0) {
        for(auto& iter : satelliteLogicVector) {
            for(auto& iter1 : playerBulletLogicVector) {
                if(collisionDetection.didObjectsCollide(iter, iter1)) {
                    iter1.setLife(false);
                    iter.decreaseHealth(iter1.getDamage());
                }
            }
        }
    }

    if(satelliteBulletLogic.size() > 0) {
        for(auto& iter : satelliteBulletLogic) {
            if(collisionDetection.didObjectsCollide(player, iter) == true) {
                iter.setLife(false);
                player.reduceHealth(iter.getDamage());
            }
        }
    }

    if(_laserGeneratorLogic.size() > 0) {
        for(unsigned int index = 0; index < _laserGeneratorLogic[0].getLaserGeneratorEnemyLogicVector().size(); index++) {
            if(playerBulletLogicVector.size() > 0) {
                for(auto& iter : playerBulletLogicVector) {
                    if(collisionDetection.didObjectsCollide(
                           iter, _laserGeneratorLogic[0].getLaserGeneratorEnemyLogicVector()[index]) == true) {
                        iter.setLife(false);
                        _laserGeneratorLogic[0].reduceHealthOfGenerator(index, iter.getDamage());
                    }
                }
            }
            if(collisionDetection.didObjectsCollide(
                   player, _laserGeneratorLogic[0].getLaserGeneratorEnemyLogicVector()[index]) == true) {
                player.reduceHealth(20);
            }
        }
        for(unsigned int index = 0; index < _laserGeneratorLogic[0].getLaserGeneratorBulletLogicVector().size(); index++) {
            if(collisionDetection.didObjectsCollide(
                   player, _laserGeneratorLogic[0].getLaserGeneratorBulletLogicVector()[index]) == true) {
                player.reduceHealth(20);
                break;
            }
        }
    }

    if(asteroidLogicVector.size() > 0) {
        for(auto& iter : asteroidLogicVector) {
            if(collisionDetection.didObjectsCollide(iter, player) == true) {
                player.reduceHealth(iter.getDamage());
                iter.setLife(false);
            }
            if(playerBulletLogicVector.size() > 0) {
                for(auto& iter1 : playerBulletLogicVector) {
                    if(collisionDetection.didObjectsCollide(iter1, iter) == true) {
                        iter1.setLife(false);
                    }
                }
            }
        }
    }
}

void GameLogic::createSatellites()
{
    int numberOfSatellites = 3;
    float distanceFromPlayer = 0.6;
    int satelliteSize = 30;
    for(auto i = 0; i < numberOfSatellites; i++) {
        SatelliteLogic satelliteLogic(
            player.getXposition() - radius * distanceFromPlayer * (cos(player.getTheta())) + satelliteSize * i,
            player.getYposition() - radius * distanceFromPlayer * (sin(player.getTheta())) + satelliteSize * i, 0.05);
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
            iter.setLife(false);
        }
    }
}

std::vector<EnemyBulletLogic> GameLogic::getSatellietBulletLogicVector()
{
    return satelliteBulletLogic;
}

void GameLogic::deleteSatelliteBulletLogic(int index)
{
    satelliteBulletLogic.erase(satelliteBulletLogic.begin() + index);
}

void GameLogic::updateSatelliteBullets(int index)
{

    satelliteBulletLogic[index].move();
}

void GameLogic::updateLaserLogic()
{
    checkLaserGeneratorScope();
    if(_laserGeneratorLogic.size() > 0) {
        _laserGeneratorLogic[0].move();
    }
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
        for(auto& iter : _laserGeneratorLogic[0].getLaserGeneratorEnemyLogicVector()) {
            if(iter.getXposition() < 0 || iter.getXposition() > GameXWindow || iter.getYposition() < 0 ||
                iter.getYposition() > GameYWindow) {
                isOutOfScope = true;
            }
        }
    }
    if(isOutOfScope == true) {
        _laserGeneratorLogic[0].setGeneratorEnemyLife(0, false);
    }
}

void GameLogic::createAsteroid()
{
    AsteroidLogic asteroidLogic(player.getTheta());
    asteroidLogicVector.push_back(asteroidLogic);
}

void GameLogic::updateAsteroidLogic()
{
    if(asteroidLogicVector.size() > 0) {
        checkAsteroidBounds();
        for(auto& iter : asteroidLogicVector) {
            iter.move();
        }
    }
}

void GameLogic::checkAsteroidBounds()
{
    for(auto& iter : asteroidLogicVector) {
        if(iter.getXposition() < 0 || iter.getXposition() > GameXWindow || iter.getYposition() < 0 ||
            iter.getYposition() > GameYWindow) {
            iter.setOutOfBounds(true);
        }
    }
}

void GameLogic::deleteOutOfScopeAsteroids(int index)
{
    if(asteroidLogicVector.size() > 0) {
        asteroidLogicVector.erase(asteroidLogicVector.begin() + index);
    }
}

std::vector<LaserGeneratorLogic> GameLogic::getlaserGeneratorLogic()
{
    return _laserGeneratorLogic;
}

void GameLogic::deleteLaserGenerator()
{
    if(_laserGeneratorLogic.size() > 0) {
        _laserGeneratorLogic.clear();
    }
}

void GameLogic::deletePlayerBullet(int index)
{
    playerBulletLogicVector.erase(playerBulletLogicVector.begin() + index);
}

std::vector<EnemyLogic> GameLogic::getEnemyLogicVector()
{
    return enemyLogicVector;
}

void GameLogic::deleteEnemyLogic(int index)
{
    int killedEnemyPoints = 15;
    enemyLogicVector.erase(enemyLogicVector.begin() + index);
    score.increasePoints(killedEnemyPoints);
}

void GameLogic::setEnemyBounds(bool isInBounds, int index)
{
    enemyLogicVector[index].setOutofBounds(isInBounds);
}

void GameLogic::moveEnemyToCenter(int index)
{
    enemyLogicVector[index].moveToCenter(CenterXGameWindow, CenterYGameWindow, player.getTheta());
}

void GameLogic::clearEnemyBullet(int index)
{
    enemyLogicVector[index].clearEnemyBulletVector();
}

std::vector<SatelliteLogic> GameLogic::getSatelliteLogicVector()
{
    return satelliteLogicVector;
}

void GameLogic::deleteSatelliteLogic(int index)
{
    int killedSatellitePoints = 25;
    satelliteLogicVector.erase(satelliteLogicVector.begin() + index);
    score.increasePoints(killedSatellitePoints);
}

std::vector<AsteroidLogic> GameLogic::getAsteroidLogicVector()
{
    return asteroidLogicVector;
}

void GameLogic::saveScoretoFile()
{
    score.storeScore();
}

int GameLogic::getHighScore()
{
    return score.getHighestScore();
}

int GameLogic::getCurrentScore()
{
    return score.getScore();
}