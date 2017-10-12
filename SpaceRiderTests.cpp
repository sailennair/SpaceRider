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

TEST_CASE("MoveLeftAndMoveRightXAxisFunctionsWorkCorrectly")
{
    PlayerLogic playerLogic;
    playerLogic.moveLeftX();
    CHECK(playerLogic.getXposition() == 372);
    playerLogic.moveRightX();
    CHECK(playerLogic.getXposition() == 380);
}

TEST_CASE("MoveLeftAndMoveRightYAxisFunctionsWorkCorrectly")
{
    PlayerLogic playerLogic;
    playerLogic.moveLeftY();
    CHECK(playerLogic.getYposition() == 544);
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

TEST_CASE("EnemyMovesCorrectly")
{
    EnemyLogic enemyLogic(CenterXGameWindow, CenterYGameWindow, PI);
    enemyLogic.move();
    CHECK(enemyLogic.getXposition() == 388);
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

TEST_CASE("AsteroidLifeCanBeSet")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.isAlive() == true);
    asteroidLogic.setLife(false);
    CHECK(asteroidLogic.isAlive() == false);
}

TEST_CASE("AsteroidOutOfBoundsCanBeSet")
{
    AsteroidLogic asteroidLogic(PI / 4);
    CHECK(asteroidLogic.isOutOfBounds() == false);
    asteroidLogic.setOutOfBounds(true);
    CHECK(asteroidLogic.isOutOfBounds() == true);
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