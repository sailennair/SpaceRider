#include "GameWindow.h"

GameWindow::GameWindow()
{

    GamePresentation _gamePresentation();
}

void GameWindow::runGame()
{

    introductionWindow.run();

    introductionWindow.closeWindow();

    generateWindow();

    _window.close();

    finalWindow.run();

    finalWindow.closeWindow();
}

void GameWindow::generateWindow()

{

    FireAnimation fireanimation(CenterXGameWindow - 32, CenterYGameWindow - 32);
    sf::RenderWindow _window(sf::VideoMode(GameXWindow, GameYWindow), "My Window");

    _window.setVerticalSyncEnabled(true);
    int timer = 0;
    int enemies = 0;
    bool isFiring = false;
    int enemyTime = 100;
    int satellietTime = 450;
    int satelliteBulletTime = 75;
    int asteroidtime = 175;
    int laserTime = 125;
    createLogo();
    while(_window.isOpen()) {

        sf::Event event;
        if(timer % enemyTime == 0 && enemies < NumberOfEnemies) {
            _gamePresentation.gameLogic_shared_pointer->createEnemyLogicObject();
            _gamePresentation.createEnemyPresentationObject();
            enemies++;
        }

        if(timer % satellietTime == 0 && _gamePresentation.getSatellitePresentationVector().size() == 0 && timer > 0) {

            _gamePresentation.gameLogic_shared_pointer->createSatellites();

            _gamePresentation.createSatellitePresenetation();
        }

        if(timer % satelliteBulletTime == 0 && _gamePresentation.getSatellitePresentationVector().size() > 0) {

            _gamePresentation.gameLogic_shared_pointer->fireSatelliteBulletLogic();

            _gamePresentation.createSatelliteBulletPresentation();
        }

        if(timer % asteroidtime == 0 && _gamePresentation.getAsteroidPresentationVector().size() == 0 && timer > 0) {
            _gamePresentation.gameLogic_shared_pointer->createAsteroid();
            _gamePresentation.createAsteroidPresentation();
        }

        if(timer % laserTime == 0 && timer > 0 && _gamePresentation.getLaserGeneratorPresentation().size() == 0) {
            _gamePresentation.gameLogic_shared_pointer->createLaserGeneratorLogic();
            _gamePresentation.createLaserGenerator();
        }

        while(_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                _window.close();
                break;
            }
            if(event.key.code == sf::Keyboard::A) {
                _direction = Direction::LEFT;
                checkKeyBoardEvent();
            }

            if(event.key.code == sf::Keyboard::D) {
                _direction = Direction::RIGHT;
                checkKeyBoardEvent();
            }

            if(event.key.code == sf::Keyboard::Space) {
                isFiring = true;
            }
        }

        if(isFiring == true) {
            firePlayerBullet();
            isFiring = false;
        }

        _gamePresentation.gameLogic_shared_pointer->checkCollision();
        updatePlayer();
        updateAllEnemies();

        _window.clear(sf::Color::Black);
        renderCharacters(_window);
        _window.draw(_logo);
        fireanimation.draw(_window);
        _window.display();

        timer++;

        if(_gamePresentation.getEnemiesKilled() == NumberOfEnemies ||
            _gamePresentation.gameLogic_shared_pointer->isPlayerDead() == true) {
            break;
        }
        if(timer == 1000) {
            timer = 0;
        }
    }

    if(_gamePresentation.getEnemiesKilled() == NumberOfEnemies) {
        finalWindow.setPLayerLostGame(false);

    } else {
        finalWindow.setPLayerLostGame(true);
    }

    _gamePresentation.gameLogic_shared_pointer->saveScoretoFile();
}

void GameWindow::renderCharacters(RenderWindow& window)
{

    _gamePresentation.drawAllBullets(window);
    _gamePresentation.drawAllEnemies(window);
    _gamePresentation.renderPlayerSprite(window);
    _gamePresentation.drawSatellites(window);
    _gamePresentation.drawSatelliteBullets(window);
    _gamePresentation.drawLaserGenerator(window);
    _gamePresentation.drawAsteroid(window);
    _gamePresentation.drawScorePresentation(window);
}

void GameWindow::checkKeyBoardEvent()
{
    _gamePresentation.gameLogic_shared_pointer->playerUpdate(_direction);
    _gamePresentation.upDatePlayerPosition();
}

void GameWindow::firePlayerBullet()
{
    _gamePresentation.gameLogic_shared_pointer->createPlayerBullet();
    _gamePresentation.createPlayerBulletPresentation();
}

void GameWindow::updatePlayer()
{
    _gamePresentation.updateScorePresentation();
    _gamePresentation.gameLogic_shared_pointer->checkBulletScope();
    _gamePresentation.gameLogic_shared_pointer->playerBulletUpdate();
    _gamePresentation.upDatePlayerBulletPresentation();
    _gamePresentation.setPlayerLifeCount();
    _gamePresentation.checkPlayerPresentationLifeDead();
}

void GameWindow::updateAllEnemies()
{
    _gamePresentation.gameLogic_shared_pointer->updateEnemyLogic();
    _gamePresentation.updateEnemyPresentation();
    _gamePresentation.gameLogic_shared_pointer->checkEnemyScope();
    _gamePresentation.deleteDeadEnemies();
    _gamePresentation.gameLogic_shared_pointer->updateSatelliteLogic();
    _gamePresentation.gameLogic_shared_pointer->checkSatelliteBulletScope();
    _gamePresentation.gameLogic_shared_pointer->updateLaserLogic();
    _gamePresentation.gameLogic_shared_pointer->updateLaserLogic();
    _gamePresentation.updateLaserGeneratorPresentation();
    _gamePresentation.deleteLaserGenerator();
    _gamePresentation.gameLogic_shared_pointer->updateAsteroidLogic();
    _gamePresentation.updateAsteroidPresentation();
    _gamePresentation.deleteOutofScopeAsteroidsPresentation();
}

void GameWindow::createLogo()
{
    if(!_logoTexture.loadFromFile("SpaceRider.PNG")) {
        std::cerr << "Error Loading logo Texture";
    }
    _logoTexture.setSmooth(true);
    _logo.setTexture(_logoTexture);
    _logo.setScale(sf::Vector2f(0.25, 0.25));
    _logo.setPosition(630, 20);
}