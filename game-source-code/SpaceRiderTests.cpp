#include "GameCommonData.h"
#include "PlayerLogic.h"
#include "PlayerPresentation.h"
#include "EnemyLogic.h"
#include "EnemyPresentation.h"
#include "PlayerBullet.h"
#include "PlayerBulletPresentation.h"
#include "EnemyBulletLogic.h"
#include "EnemyBulletPresentation.h"
#include "SatelliteLogic.h"
#include "SatellitePresentation.h"
#include "AsteroidLogic.h"
#include "AsteroidPresentation.h"
#include "LaserGeneratorLogic.h"
#include "LaserGeneratorPresentation.h"
#include "LifeLogic.h"
#include "Score.h"
#include "ScorePresentation.h"
#include "CollisionDetection.h"
#include "GameLogic.h"
#include "GamePresentation.h"
#include "GameWindow.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#define PI 3.14159265

//**** Tests for PlayerLogic****//
TEST_CASE("CorrectXPositionOfPlayerisReturend")
{
    PlayerLogic playerLogic;
    auto playerPosition = playerLogic.getXposition();
    CHECK(playerPosition == PlayerXPosition);
}

TEST_CASE("CorrectYPositionOfPlayerisReturend")
{
    PlayerLogic playerLogic;
    auto playerPosition = playerLogic.getYposition();
    CHECK(playerPosition == PlayerYPosition);
}

TEST_CASE("PlayerMovesLeftCorrectlyXAxis")
{
    PlayerLogic playerLogic;
    playerLogic.moveLeftX();
    CHECK(playerLogic.getXposition() == 372);
}

TEST_CASE("PlayerMovesRightCorrectlyXAxis")
{
    PlayerLogic playerLogic;
    playerLogic.moveRightX();
    CHECK(playerLogic.getXposition() == 388);
}

TEST_CASE("PlayerMovesLeftCorrectlyYaxis")
{
    PlayerLogic playerLogic;
    playerLogic.moveLeftY();
    CHECK(playerLogic.getYposition() == 544);
}

TEST_CASE("PlayerMovesRIghtCorrectlyYaxis")
{
    PlayerLogic playerLogic;
    playerLogic.moveRightY();
    CHECK(playerLogic.getYposition() == 544);
}

TEST_CASE("PlayerMovesCorrectlyInLeftDirection")
{
    PlayerLogic playerLogic;
    playerLogic.playerMove(Direction::LEFT);
    CHECK(playerLogic.getAngleofRotation() == 4);
    CHECK(playerLogic.getXposition() == 372);
    CHECK(playerLogic.getYposition() == 544);
}

TEST_CASE("PlayerMovesCorrectlyInRIghtDirection")
{
    PlayerLogic playerLogic;
    playerLogic.playerMove(Direction::RIGHT);
    CHECK(playerLogic.getAngleofRotation() == -4);
    CHECK(playerLogic.getXposition() == 388);
    CHECK(playerLogic.getYposition() == 544);
}

TEST_CASE("PlayerHealthReduces")
{
    PlayerLogic playerLogic;
    CHECK(playerLogic.getHealth() == 100);
    playerLogic.reduceHealth(5);
    CHECK(playerLogic.getHealth() == 95);
}

TEST_CASE("PlayerDiesWhenHealthisO")
{
    PlayerLogic playerLogic;
    CHECK(playerLogic.getHealth() == 100);
    CHECK(playerLogic.isAlive() == true);
    playerLogic.reduceHealth(100);
    CHECK(playerLogic.getHealth() == 0);
    CHECK(playerLogic.isAlive() == false);
}

TEST_CASE("CenterXPositionofPlayerisReturned")
{
    PlayerLogic playerLogic;
    CHECK(playerLogic.getCenterXPosition() == CenterXGameWindow);
}

TEST_CASE("CenterYPositionofPlayerisReturned")
{
    PlayerLogic playerLogic;
    CHECK(playerLogic.getCenterYPosition() == GameYWindow - PlayerHeight / 2);
}

TEST_CASE("PlayerPositionResets")
{
    PlayerLogic playerLogic;
    playerLogic.playerMove(Direction::LEFT);
    playerLogic.playerMove(Direction::LEFT);
    CHECK(playerLogic.getXposition() == 355);
    CHECK(playerLogic.getYposition() == 542);
    CHECK(playerLogic.getTheta() != PI / 2);
    playerLogic.playerRestart();
    CHECK(playerLogic.getXposition() == PlayerXPosition);
    CHECK(playerLogic.getYposition() == PlayerYPosition);
    CHECK(doctest::Approx(playerLogic.getTheta()) == PI / 2);
}

//**** Tests for PlayerPresentation****//

TEST_CASE("CheckIfPlayerISSetAtCorrectPosition")
{
    PlayerPresentation playerPresentation;
    playerPresentation.setPositionofPlayer(200, 400);
    CHECK(playerPresentation.getPlayer().getPosition().x == 200);
    CHECK(playerPresentation.getPlayer().getPosition().y == 400);
}

TEST_CASE("CheckIfPlayerRotatesCorrectly")
{
    PlayerPresentation playerPresentation;
    playerPresentation.rotateSprite(0.5f);
    CHECK(playerPresentation.getPlayer().getRotation() == 0.5f);
}

TEST_CASE("CheckIfPlayerRestartsCorrectly")
{
    PlayerPresentation playerPresentation;
    playerPresentation.rotateSprite(0.5f);
    CHECK(playerPresentation.getPlayer().getRotation() == 0.5f);
    playerPresentation.restartPlayerPresentation();
    CHECK(playerPresentation.getPlayer().getRotation() == 0);
}

//**** Tests for EnemyLogic****//
TEST_CASE("EnemyReturnsCorrectXLocation")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getXposition() == CenterXGameWindow - 10);
}

TEST_CASE("EnemyReturnsCorrectYLocation")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getYposition() == CenterYGameWindow);
}

TEST_CASE("EnemyCenterXLocationisCorrect")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getCenterXPosition() == enemyLogic.getXposition() + 20);
}

TEST_CASE("EnemyCenterYLocationisCorrect")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getCenterYPosition() == enemyLogic.getYposition() + 20);
}

TEST_CASE("EnemyMovesCorrectlyXDirection")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    enemyLogic.move();
    CHECK(enemyLogic.getXposition() == 388);
}

TEST_CASE("EnemyMovesCorrectlyYdirection")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    enemyLogic.move();
    CHECK(enemyLogic.getYposition() == 300);
}

TEST_CASE("EnemyMovesToCenterCorrectly")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    enemyLogic.move();
    CHECK(enemyLogic.getXposition() == 388);
    CHECK(enemyLogic.getYposition() == 300);
    enemyLogic.moveToCenter(200, 200, PI / 2);
    CHECK(enemyLogic.getXposition() == 200);
    CHECK(enemyLogic.getXposition() == 200);
}

TEST_CASE("EnemyHealthDiesWhenHealthIs0orLess")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.isAlive() == true);
    enemyLogic.reduceHealth(20); // health of enemy is 20
    CHECK(enemyLogic.isAlive() == false);
}

TEST_CASE("EnemyBoundsCanBeSet")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.isOutOfBounds() == false);
    enemyLogic.setOutofBounds(true);
    CHECK(enemyLogic.isOutOfBounds() == true);
}

TEST_CASE("EnemyCollisionRadiusISReturnedCorrectly")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getRadius() == 15);
}

TEST_CASE("EnemyIsCreatedWithBulletVectorWithin")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getEnemyBulletLogicVector().size() == 1);
}

TEST_CASE("EnemyLifeCanBeSet")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.isAlive() == true);
    enemyLogic.setLife(false);
    CHECK(enemyLogic.isAlive() == false);
}

TEST_CASE("EnemyBulletLifeCanBeSetFromEnemy")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getEnemyBulletLogicVector().size() == 1);
    CHECK(enemyLogic.getEnemyBulletLogicVector()[0].isAlive() == true);
    enemyLogic.setEnemyBulletLife(false);
    CHECK(enemyLogic.getEnemyBulletLogicVector()[0].isAlive() == false);
}

TEST_CASE("EnemyBulletVectorInEnemyCanBeCleared")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    CHECK(enemyLogic.getEnemyBulletLogicVector().size() == 1);
    enemyLogic.clearEnemyBulletVector();
    CHECK(enemyLogic.getEnemyBulletLogicVector().size() == 0);
}

//**** Tests for EnemyPresentation****//
TEST_CASE("EnemyDefaultConstructorsWorkIndependantly")
{
    EnemyPresentation enemyPresentation;
    CHECK(enemyPresentation.getEnemySprite().getScale().x == 0.1f);
}

TEST_CASE("EnemyConstructorsWorkIndependantly")
{
    EnemyPresentation enemyPresentation(1);
    CHECK(enemyPresentation.getEnemySprite().getScale().x == 0.6f);
}

TEST_CASE("EnemyMovesCorrectlyWhenUpdated")
{
    EnemyPresentation enemyPresentation;
    enemyPresentation.updateEnemy(100, 150);
    CHECK(enemyPresentation.getEnemySprite().getPosition().x == 100);
    CHECK(enemyPresentation.getEnemySprite().getPosition().y == 150);
}

TEST_CASE("EnemyBulletPresentationVectorClears")
{
    EnemyPresentation enemyPresentation;
    CHECK(enemyPresentation.getEnemyBulletPresentationVector().size() == 1);
    enemyPresentation.deleteEnemyBulletPresentation();
    CHECK(enemyPresentation.getEnemyBulletPresentationVector().size() == 0);
}

TEST_CASE("EnemyBulletUpDatesCorrectly")
{
    EnemyPresentation enemyPresentation;
    enemyPresentation.updateEnemyBullet(50, 60);
    CHECK(enemyPresentation.getEnemyBulletPresentationVector()[0].getEnemyBullet().getPosition().x == 50);
}

TEST_CASE("EnemyBulletUpDatesCorrectly")
{
    EnemyPresentation enemyPresentation;
    enemyPresentation.updateEnemyBullet(50, 60);
    CHECK(enemyPresentation.getEnemyBulletPresentationVector()[0].getEnemyBullet().getPosition().y == 60);
}

TEST_CASE("EnemyBulletUpDatesToCenterWhenEnemyGosToCenter")
{
    EnemyPresentation enemyPresentation;
    enemyPresentation.updateEnemyBullet(50, 60);
    CHECK(enemyPresentation.getEnemyBulletPresentationVector()[0].getEnemyBullet().getPosition().x == 50);
    CHECK(enemyPresentation.getEnemyBulletPresentationVector()[0].getEnemyBullet().getPosition().y == 60);
    enemyPresentation.updateEnemyBullet(CenterXGameWindow, CenterYGameWindow);
    CHECK(
        enemyPresentation.getEnemyBulletPresentationVector()[0].getEnemyBullet().getPosition().x == CenterXGameWindow);
    CHECK(
        enemyPresentation.getEnemyBulletPresentationVector()[0].getEnemyBullet().getPosition().y == CenterYGameWindow);
}

//**** Tests for PlayerBulletLogic ****//

TEST_CASE("PlayerBulletRetrunsCorrectXPosition")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    int x = 100 + PlayerWidth * cos(PI / 4);
    CHECK(playerBulletLogic.getXposition() == x);
}

TEST_CASE("PlayerBulletRetrunsCorrectYPosition")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    int x = 200 + (PlayerHeight / 2) * sin(PI / 4);
    CHECK(playerBulletLogic.getYposition() == x);
}

TEST_CASE("PlayerBulletMovesCorrectly")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    int x = 100 + PlayerWidth * cos(PI / 4);
    CHECK(playerBulletLogic.getXposition() == x);
    int y = 200 + (PlayerHeight / 2) * sin(PI / 4);
    CHECK(playerBulletLogic.getYposition() == y);
    playerBulletLogic.move();
    CHECK(playerBulletLogic.getXposition() == 149);
    CHECK(playerBulletLogic.getYposition() == 228);
}

TEST_CASE("PlayerBulletLifeISreturnedCorrectly")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    CHECK(playerBulletLogic.isAlive() == true);
}

TEST_CASE("PlayerBulletlifeCanBeSet")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    CHECK(playerBulletLogic.isAlive() == true);
    playerBulletLogic.setLife(false);
    CHECK(playerBulletLogic.isAlive() == false);
}

TEST_CASE("PlayerBulletRadiusisReturned")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    CHECK(playerBulletLogic.getRadius() == 3);
}

TEST_CASE("PlayerBulletForConstructorType1")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 1);
    CHECK(playerBulletLogic.getRadius() == 3);
    CHECK(playerBulletLogic.getDamage() == 5);
}

TEST_CASE("PlayerBulletForConstructorType2")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 2);
    CHECK(playerBulletLogic.getRadius() == 6);
    CHECK(playerBulletLogic.getDamage() == 20);
}

TEST_CASE("PlayerBulletFiresCorrectly")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 2);
    CHECK(playerBulletLogic.getXposition() == 133.0f);
    CHECK(playerBulletLogic.getYposition() == 224.0f);
    playerBulletLogic.fire();
    CHECK(playerBulletLogic.getXposition() == 149.0f);
    CHECK(playerBulletLogic.getYposition() == 228.0f);
}

TEST_CASE("PlayerBulletCenterXPositionIsReturnedCorrectly")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 2);
    CHECK(playerBulletLogic.getCenterXPosition() == 103.0f);
}

TEST_CASE("PlayerBulletCenterYPositionIsReturnedCorrectly")
{
    PlayerBullet playerBulletLogic(100, 200, PI / 4, 2);
    CHECK(playerBulletLogic.getCenterYPosition() == 203.0f);
}

//**** Tests for PlayerBulletPresentation ****//
TEST_CASE("PlayerBulletPresentationSizeChangesWIthType")
{
    PlayerBulletPresentation playerBulletPresentation(100, 200, 1);
    CHECK(playerBulletPresentation.getBullet().getFillColor() == sf::Color::Green);
    CHECK(playerBulletPresentation.getBullet().getRadius() == 3);
}

TEST_CASE("PlayerBulletPresentationSizeChangesWIthType")
{
    PlayerBulletPresentation playerBulletPresentation(100, 200, 2);
    CHECK(playerBulletPresentation.getBullet().getFillColor() == sf::Color::Red);
    CHECK(playerBulletPresentation.getBullet().getRadius() == 6);
}

TEST_CASE("PlayerBulletUpdatesPosition")
{
    PlayerBulletPresentation playerBulletPresentation(100, 200, 1);
    playerBulletPresentation.updateBullet(55, 65);
    CHECK(playerBulletPresentation.getBullet().getPosition().x == 55);
    CHECK(playerBulletPresentation.getBullet().getPosition().y == 65);
}

//**** Tests for EnemyBulletLogic ****//
TEST_CASE("EnemyBulletReturnsCorrectXPosition")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    int x = 100 + (10) * cos(PI / 4);
    int y = enemyBulletLogic.getXposition();
    CHECK(y == x);
}

TEST_CASE("EnemyBulletReturnsCorrectYPosition")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    int x = enemyBulletLogic.getYposition();
    int y = 200 + (10) * sin(PI / 4);
    CHECK(x == y);
}

TEST_CASE("EnemyBulletMovesCorrectly")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    int x = enemyBulletLogic.getXposition();
    int y = enemyBulletLogic.getYposition();
    enemyBulletLogic.move();
    int newx = x + 100 * (cos(PI / 4) * 0.015); // bullet speed is 0.015
    int newy = y + 200 * (sin(PI / 4) * 0.015);
    int actualx = enemyBulletLogic.getXposition();
    int actualy = enemyBulletLogic.getYposition();
    CHECK(newx == actualx);
    CHECK(newy == actualy);
}

TEST_CASE("EnemyBulletLifeCanBEChecked")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    CHECK(enemyBulletLogic.isAlive() == true);
}

TEST_CASE("EnemyBulletLifeCanBeSet")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    CHECK(enemyBulletLogic.isAlive() == true);
    enemyBulletLogic.setLife(false);
    CHECK(enemyBulletLogic.isAlive() == false);
}

TEST_CASE("EnemyBulletDamageCanBeRetrieved")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    CHECK(enemyBulletLogic.getDamage() == 5);
}

TEST_CASE("EnemyBulletDamageCanBeChanged")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    CHECK(enemyBulletLogic.getDamage() == 5);
    enemyBulletLogic.setDamage(20);
    CHECK(enemyBulletLogic.getDamage() == 20);
}

TEST_CASE("EnemyBulletRadiusCanBeRetrieved")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    CHECK(enemyBulletLogic.getRadius() == 5);
}

TEST_CASE("EnemyBulletCenterXPositionisCorredr")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    int centerX = enemyBulletLogic.getCenterXPosition();
    CHECK(centerX == 102);
}

TEST_CASE("EnemyBulletCenterXPositionisCorredr")
{
    EnemyBulletLogic enemyBulletLogic(100, 200, PI / 4);
    int centerY = enemyBulletLogic.getCenterYPosition();
    CHECK(centerY == 202);
}

//**** Tests for EnemyBulletPresentation ****//

TEST_CASE("EnemyBulletDefaultConstructorHasLargeRadiusAndIsRed")
{
    EnemyBulletPresentation enemyBulletPresentation;
    CHECK(enemyBulletPresentation.getEnemyBullet().getRadius() == 10);
    CHECK(enemyBulletPresentation.getEnemyBullet().getFillColor() == sf::Color::Red);
}

TEST_CASE("EnemyBulletOverloadedConstructorHasLargeRadiusAndIsBlue")
{
    EnemyBulletPresentation enemyBulletPresentation(100, 200);
    CHECK(enemyBulletPresentation.getEnemyBullet().getRadius() == 2.5);
    CHECK(enemyBulletPresentation.getEnemyBullet().getFillColor() == sf::Color::Blue);
}

TEST_CASE("EnemyBulletPresentationWillSetBulletAtcorrectLocation")
{
    EnemyBulletPresentation enemyBulletPresentation(100, 200);
    CHECK(enemyBulletPresentation.getEnemyBullet().getRadius() == 2.5);
    enemyBulletPresentation.updateEnemyBullet(125, 155);
    CHECK(enemyBulletPresentation.getEnemyBullet().getPosition().x == 125);
    CHECK(enemyBulletPresentation.getEnemyBullet().getPosition().y == 155);
}

//**** Tests for SatelliteLogic ****//
TEST_CASE("SatelliteXPositionISReturend")
{
    SatelliteLogic satellietLogic(100, 120, PI / 4);
    CHECK(satellietLogic.getXposition() == 100);
}

TEST_CASE("SatelliteYPositionISReturend")
{
    SatelliteLogic satellietLogic(100, 120, PI / 4);
    CHECK(satellietLogic.getYposition() == 120);
}

TEST_CASE("CheckIFSatellietMovesCorrectly")
{
    SatelliteLogic satellietLogic(100, 120, PI / 4);
    CHECK(satellietLogic.getXposition() == 100);
    CHECK(satellietLogic.getYposition() == 120);
    satellietLogic.move();
    CHECK(satellietLogic.getXposition() == 110);
    int y = satellietLogic.getYposition();
    CHECK(y == 115);
}

TEST_CASE("SatellietLifeISRetrievec")
{
    SatelliteLogic satelliteLogic(100, 120, PI / 4);
    CHECK(satelliteLogic.isAlive() == true);
}

TEST_CASE("SatelliteWillDieWhenHealthis0")
{
    SatelliteLogic satellietLogic(100, 120, PI / 4);
    CHECK(satellietLogic.isAlive() == true);
    satellietLogic.decreaseHealth(20);
    CHECK(satellietLogic.isAlive() == false);
}

TEST_CASE("SatelliteCollisionRadiusIsReturned")
{
    SatelliteLogic satellietLogic(100, 120, PI / 4);
    CHECK(satellietLogic.getRadius() == 15);
}

TEST_CASE("SatelliteRerturnsTheCorrectCenterXPosition")
{
    SatelliteLogic satelliteLogic(100, 120, PI / 4);
    int centerx = satelliteLogic.getCenterXPosition();
    CHECK(centerx == 107);
}

TEST_CASE("SatelliteRerturnsTheCorrectCenterYPosition")
{
    SatelliteLogic satelliteLogic(100, 120, PI / 4);
    int centerY = satelliteLogic.getCenterYPosition();
    CHECK(centerY == 127);
}

//**** Tests for AsteroidLogic ****//
TEST_CASE("AsteroidXPositionIsReturenedCorrectly")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.getXposition() == CenterXGameWindow);
}

TEST_CASE("AsteroidYPositionIsReturenedCorrectly")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.getYposition() == CenterYGameWindow);
}

TEST_CASE("AsteroidMovesCorrectly")
{
    AsteroidLogic asteroidLogic(PI / 4);
    int oldx = asteroidLogic.getXposition();
    int oldy = asteroidLogic.getYposition();
    CHECK(oldx == CenterXGameWindow);
    CHECK(oldy == CenterYGameWindow);
    asteroidLogic.move();
    int actualx = asteroidLogic.getXposition();
    int newX = oldx + CenterXGameWindow * cos(PI / 4) * 0.005; // enemyspeed is 0.005
    CHECK(actualx == newX);
    int actualy = asteroidLogic.getYposition();
    int newY = oldy + CenterYGameWindow * sin(PI / 4) * 0.005;
    CHECK(actualy == newY);
}

TEST_CASE("AngleOFAsteroidIsReturened")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(doctest::Approx(asteroidLogic.getAngleofRotation()) == PI / 4);
}
TEST_CASE("AsteroidLifeCanBeRetrieved")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.isAlive() == true);
}

TEST_CASE("AsteroidLifeCanBeSet")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.isAlive() == true);
    asteroidLogic.setLife(false);
    CHECK(asteroidLogic.isAlive() == false);
}

TEST_CASE("AsteroidBoundsCanBERetrived")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.isOutOfBounds() == false);
}

TEST_CASE("AsteroidOutOfBoundsCanBeSet")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.isOutOfBounds() == false);
    asteroidLogic.setOutOfBounds(true);
    CHECK(asteroidLogic.isOutOfBounds() == true);
}

TEST_CASE("AsteroidCenterXPositionCanBeRetrived")
{
    AsteroidLogic asteroidLogic(PI / 4);
    int centerX = asteroidLogic.getCenterXPosition();
    CHECK(centerX == 420);
}

TEST_CASE("AsteroidCenterYPositionCanBeRetrived")
{
    AsteroidLogic asteroidLogic(PI / 4);
    int centerY = asteroidLogic.getCenterYPosition();
    CHECK(centerY == 320);
}

TEST_CASE("AsteroidDamageCanbeREtrieved")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.getDamage() == 20);
}

//**** Tests for AsteroidPresentation ****//
TEST_CASE("AsteroidSpriteUpDatesPosition")
{
    AsteroidPresentation asteroidPresentation;
    asteroidPresentation.updateAsteroid(200, 150);
    CHECK(asteroidPresentation.getAsteroidSprite().getPosition().x == 200);
    CHECK(asteroidPresentation.getAsteroidSprite().getPosition().y == 150);
}

//**** Tests for LaserGeneratorLogic ****//
// Laser generator makes use of both enemy and enemy bullets, hence both of these have been tested already
TEST_CASE("HealthOfLaserGeneratoDecreasesTillitDies")
{
    LaserGeneratorLogic laserGeneratorLogic;
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[1].isAlive() == true);
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[0].isAlive() == true);
    laserGeneratorLogic.reduceHealthOfGenerator(1, 15);
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[1].isAlive() == false);
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[0].isAlive() == true);
}

TEST_CASE("LifeOfLaserGeneratorCanBeSet")
{
    LaserGeneratorLogic laserGeneratorLogic;
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[1].isAlive() == true);
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[0].isAlive() == true);
    laserGeneratorLogic.setGeneratorEnemyLife(1, false);
    CHECK(laserGeneratorLogic.getLaserGeneratorEnemyLogicVector()[1].isAlive() == false);
}

//**** Tests for LaserGeneratorPresentation ****//

TEST_CASE("LaserGeneratorSpritePositionUpdatesX")
{
    LaserGeneratorPresentation laserGeneratorPresentation;
    CHECK(laserGeneratorPresentation.getLaserGeneratorPresentationVector()[1].getEnemySprite().getPosition().x ==
        CenterXGameWindow);
    laserGeneratorPresentation.updateLaserGeneratorEnemy(1, 200, 120);
    CHECK(laserGeneratorPresentation.getLaserGeneratorPresentationVector()[1].getEnemySprite().getPosition().x == 200);
}

TEST_CASE("LaserGeneratorSpritePositionUpdatesY")
{
    LaserGeneratorPresentation laserGeneratorPresentation;
    CHECK(laserGeneratorPresentation.getLaserGeneratorPresentationVector()[1].getEnemySprite().getPosition().y ==
        CenterYGameWindow);
    laserGeneratorPresentation.updateLaserGeneratorEnemy(1, 200, 120);
    CHECK(laserGeneratorPresentation.getLaserGeneratorPresentationVector()[1].getEnemySprite().getPosition().y == 120);
}

TEST_CASE("LaserBulletsPresentationUpDatesX")
{
    LaserGeneratorPresentation laserGeneratorPresentation;
    CHECK(laserGeneratorPresentation.getLaserBulletPresentationVector()[1].getEnemyBullet().getPosition().x == 0);
    laserGeneratorPresentation.updateLaserBulletPresentation(1, 200, 120);
    CHECK(laserGeneratorPresentation.getLaserBulletPresentationVector()[1].getEnemyBullet().getPosition().x == 200);
}

TEST_CASE("LaserBulletsPresentationUpDatesY")
{
    LaserGeneratorPresentation laserGeneratorPresentation;
    CHECK(laserGeneratorPresentation.getLaserBulletPresentationVector()[1].getEnemyBullet().getPosition().y == 0);
    laserGeneratorPresentation.updateLaserBulletPresentation(1, 200, 120);
    CHECK(laserGeneratorPresentation.getLaserBulletPresentationVector()[1].getEnemyBullet().getPosition().y == 120);
}

//**** Tests for LifeLogic ****//
TEST_CASE("LifeLogicReturnsTheCorrectXValue")
{
    LifeLogic lifeLogic(20, 40);
    CHECK(lifeLogic.getXpos() == 20);
}

TEST_CASE("LifeLogicReturnsTheCorrectYValue")
{
    LifeLogic lifeLogic(20, 40);
    CHECK(lifeLogic.getYpos() == 40);
}

TEST_CASE("LivesChangeDepeningOnHealth")
{
    LifeLogic lifeLogic(20, 40);
    CHECK(lifeLogic.getXpos() == 20);
    CHECK(lifeLogic.getYpos() == 40);
    CHECK(lifeLogic.getNumberOfLivesRemaining(100) == 5);
    CHECK(lifeLogic.getNumberOfLivesRemaining(80) == 4);
    CHECK(lifeLogic.getNumberOfLivesRemaining(60) == 3);
    CHECK(lifeLogic.getNumberOfLivesRemaining(40) == 2);
    CHECK(lifeLogic.getNumberOfLivesRemaining(20) == 1);
    CHECK(lifeLogic.getNumberOfLivesRemaining(0) == 0);
}

//**** Tests for ScoreLogic ****//
TEST_CASE("ScoreInitilisesToZeroAtStartOfGame")
{
    Score score;
    CHECK(score.getScore() == 0);
}

TEST_CASE("ScoreupDatesWhenScoreisIncreased")
{
    Score score;
    score.increasePoints(50);
    CHECK(score.getScore() == 50);
    score.increasePoints(20);
    CHECK(score.getScore() == 70);
}
//**** Tests for Collision ****//
TEST_CASE("CollisionDetcectionWorksForPlayerandEnemy")
{
    PlayerLogic playerLogic;
    playerLogic.playerMove(Direction::LEFT);
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI / 4);
    EnemyLogic enemyLogic2(CenterXGameWindow, CenterYGameWindow, playerLogic.getTheta());
    for(int i = 0; i < 100; i++) {
        enemyLogic2.move();
    }
    enemyLogic2.setRadius(100);
    CollisionDetection collisionDetection;
    CHECK(collisionDetection.didObjectsCollide(playerLogic, enemyLogic) == false);
    CHECK(collisionDetection.didObjectsCollide(playerLogic, enemyLogic2) == true);
}

TEST_CASE("EnemyBulletCollidesWithPlayer")
{
    PlayerLogic playerLogic;
    playerLogic.playerMove(Direction::LEFT);
    EnemyBulletLogic enemyBullet(
        playerLogic.getCenterXPosition(), playerLogic.getCenterYPosition(), playerLogic.getTheta());
    CollisionDetection collisionDetection;
    CHECK(collisionDetection.didObjectsCollide(playerLogic, enemyBullet) == true);
}

TEST_CASE("PlayerBulletAndEnemyCollide")
{
    PlayerBullet playerbullet(CenterXGameWindow, CenterYGameWindow, PI / 4, 2);
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI / 4);
    CollisionDetection collisionDetection;
    CHECK(collisionDetection.didObjectsCollide(playerbullet, enemyLogic) == true);
}

TEST_CASE("PlayerBulletAndAsteroidCollide")
{
    AsteroidLogic asteroid(PI / 4);
    PlayerBullet playerBullet(asteroid.getCenterXPosition(), asteroid.getCenterYPosition(), PI / 4, 2);
    CollisionDetection collisionDetection;
    CHECK(collisionDetection.didObjectsCollide(playerBullet, asteroid) == true);
}

TEST_CASE("PlayerBulletAndSatelliteCollise")
{
    SatelliteLogic satellite(100, 200, PI / 4);
    SatelliteLogic satellite2(200, 400, PI / 4);
    PlayerBullet playerBullet(100, 200, PI / 4, 2);
    CollisionDetection collisionDetection;
    CHECK(collisionDetection.didObjectsCollide(satellite, playerBullet) == true);
    CHECK(collisionDetection.didObjectsCollide(satellite2, playerBullet) == false);
}

//**** Tests for GameLogic ****//
TEST_CASE("CheckIfPlayerUpdatesCorrectlyXAxis")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getPlayerLogic().getXposition() == PlayerXPosition);
    gameLogic.playerUpdate(Direction::LEFT);
    CHECK(gameLogic.getPlayerLogic().getXposition() == 372);
}

TEST_CASE("CheckIfPlayerUpdatesCorrectlyYAxis")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getPlayerLogic().getYposition() == PlayerYPosition);
    gameLogic.playerUpdate(Direction::LEFT);
    CHECK(gameLogic.getPlayerLogic().getYposition() == 544);
}

TEST_CASE("PlayerLifeUpDates")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getPlayerLogic().getHealth() == 100);
    gameLogic.updatePlayerLife();
    CHECK(gameLogic.getPlayerLivesRemaining() == 5);
}

TEST_CASE("PlayerBulletCreatesAndStoresInVector")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getPlayerLogicBullets().size() == 0);
    gameLogic.createPlayerBullet();
    CHECK(gameLogic.getPlayerLogicBullets().size() == 1);
}

TEST_CASE("PlayerBulletTypeIsSetCorrectly")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getPlayerBulletType() == 1);
    gameLogic.setPlayerBulletType(2);
    CHECK(gameLogic.getPlayerBulletType() == 2);
}

TEST_CASE("PlayerBulletsLifeIsSetToFalseWhenItreachesThecenteroftheWindow")
{
    GameLogic gameLogic;
    gameLogic.createPlayerBullet();
    CHECK(gameLogic.getPlayerLogicBullets()[0].isAlive() == true);
    for(int i = 0; i < 100; i++) {
        gameLogic.playerBulletUpdate();
    }
    gameLogic.checkBulletScope();
    CHECK(gameLogic.getPlayerLogicBullets()[0].isAlive() == false);
}

TEST_CASE("EnemyObjectISCreatedAndStored")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getEnemyLogicVector().size() == 0);
    gameLogic.createEnemyLogicObject();
    CHECK(gameLogic.getEnemyLogicVector().size() == 1);
}

TEST_CASE("EnemyOutOFBoundsISSetWHenItMovesOutTheScree")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getEnemyLogicVector().size() == 0);
    gameLogic.createEnemyLogicObject();
    CHECK(gameLogic.getEnemyLogicVector().size() == 1);
    for(int i = 0; i < 100; i++) {
        gameLogic.updateEnemyLogic();
    }
    CHECK(gameLogic.getEnemyLogicVector()[0].isOutOfBounds() == false);
}

TEST_CASE("PlayerLifeISCheckedCorrectly")
{
    GameLogic gameLogic;
    CHECK(gameLogic.checkPlayerLifeDead() == true);
}

TEST_CASE("SatelliteObjectISCreatedAndStored")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getSatelliteLogicVector().size() == 0);
    gameLogic.createSatellites();
    CHECK(gameLogic.getSatelliteLogicVector().size() == 3);
}

TEST_CASE("CheckTheScopeOfSatelliteBullets")
{
    GameLogic gameLogic;
    gameLogic.createSatellites();
    gameLogic.fireSatelliteBulletLogic();
    CHECK(gameLogic.getSatellietBulletLogicVector().size() == 3);
    CHECK(gameLogic.getSatellietBulletLogicVector()[0].isAlive() == true);
    CHECK(gameLogic.getSatellietBulletLogicVector()[1].isAlive() == true);
    CHECK(gameLogic.getSatellietBulletLogicVector()[2].isAlive() == true);
    for(int i = 0; i < 100; i++) {
        gameLogic.updateSatelliteBullets(0);
        gameLogic.updateSatelliteBullets(1);
        gameLogic.updateSatelliteBullets(2);
    }
    gameLogic.checkSatelliteBulletScope();
    CHECK(gameLogic.getSatellietBulletLogicVector()[1].isAlive() == false);
    CHECK(gameLogic.getSatellietBulletLogicVector()[1].isAlive() == false);
    CHECK(gameLogic.getSatellietBulletLogicVector()[2].isAlive() == false);
}

TEST_CASE("LaserGeneratorsLogicIsCreated")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getlaserGeneratorLogic().size() == 0);
    gameLogic.createLaserGeneratorLogic();
    CHECK(gameLogic.getlaserGeneratorLogic().size() == 1);
}

TEST_CASE("LAserGeneratorScopeisSetToTrueWhenOutOfScope")
{
    GameLogic gameLogic;
    gameLogic.createLaserGeneratorLogic();
    CHECK(gameLogic.getlaserGeneratorLogic()[0].getLaserGeneratorEnemyLogicVector()[0].isAlive() == true);
}

TEST_CASE("AsteroidISCreated")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getAsteroidLogicVector().size() == 0);
    gameLogic.createAsteroid();
    CHECK(gameLogic.getAsteroidLogicVector().size() == 1);
}

TEST_CASE("AsteroidOuOfBoundsLifeisSettoFalse")
{
    GameLogic gameLogic;
    CHECK(gameLogic.getAsteroidLogicVector().size() == 0);
    gameLogic.createAsteroid();
    CHECK(gameLogic.getAsteroidLogicVector().size() == 1);
    gameLogic.checkAsteroidBounds();
    CHECK(gameLogic.getAsteroidLogicVector()[0].isOutOfBounds() == false);
    for(int i = 1; i < 175; i++) {
        gameLogic.updateAsteroidLogic();
    }
    gameLogic.checkAsteroidBounds();
    CHECK(gameLogic.getAsteroidLogicVector()[0].isOutOfBounds() == true);
}

TEST_CASE("EnemyMovesToCenter")
{
    GameLogic gameLogic;
    gameLogic.createEnemyLogicObject();
    CHECK(gameLogic.getEnemyLogicVector().size() == 1);
    gameLogic.moveEnemyToCenter(0);
    CHECK(gameLogic.getEnemyLogicVector()[0].getXposition() == CenterXGameWindow);
}

TEST_CASE("ScoreIncreasesBy15WhenEnemyDies")
{
    GameLogic gameLogic;
    gameLogic.createEnemyLogicObject();
    CHECK(gameLogic.getCurrentScore() == 0);
    gameLogic.deleteEnemyLogic(0);
    CHECK(gameLogic.getCurrentScore() == 15);
}

TEST_CASE("ScoreIncreasesBy25WhenEnemyDies")
{
    GameLogic gameLogic;
    gameLogic.createSatellites();
    CHECK(gameLogic.getCurrentScore() == 0);
    gameLogic.deleteSatelliteLogic(0);
    CHECK(gameLogic.getCurrentScore() == 25);
    gameLogic.deleteSatelliteLogic(1);
    CHECK(gameLogic.getCurrentScore() == 50);
    gameLogic.deleteSatelliteLogic(2);
    CHECK(gameLogic.getCurrentScore() == 75);
}

//**** Tests for GamePresentation ****//

TEST_CASE("PlayerPresentationUpDates")
{
    GamePresentation gamePresentation;
    gamePresentation.upDatePlayerPosition();
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getXposition() == PlayerXPosition);
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getYposition() == PlayerYPosition);
}

TEST_CASE("PlayerPresentationUpDateswhenPlayerMoves")
{
    GamePresentation gamePresentation;
    gamePresentation.upDatePlayerPosition();
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getXposition() == PlayerXPosition);
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getYposition() == PlayerYPosition);
    gamePresentation.gameLogic_shared_pointer->playerUpdate(Direction::LEFT);
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getXposition() == 372);
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getYposition() == 544);
    gamePresentation.gameLogic_shared_pointer->playerUpdate(Direction::RIGHT);
    gamePresentation.gameLogic_shared_pointer->playerUpdate(Direction::RIGHT);
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getXposition() == 388);
    CHECK(gamePresentation.gameLogic_shared_pointer->getPlayerLogic().getYposition() == 544);
}

// updateLaserGeneratorLogic