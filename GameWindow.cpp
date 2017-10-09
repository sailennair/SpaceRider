#include "GameWindow.h"

GameWindow::GameWindow()
{

    GamePresentation _gamePresentation();
}

void GameWindow::generateWindow()
{
    sf::RenderWindow _window(sf::VideoMode(GameXWindow, GameYWindow), "My Window");

    _window.setVerticalSyncEnabled(true);
    int timer = 0;
    int enemies = 0;
    bool isFiring = false;
    
    
    while(_window.isOpen()) {

        sf::Event event;
        if(timer % 100 == 0 && enemies < NumberOfEnemies) {
            _gamePresentation.gameLogic_shared_pointer->createEnemyLogicObject();
            _gamePresentation.createEnemyPresentationObject();
            enemies++;
            std::cout << enemies << std::endl;
        }

        if(timer % 250 == 0 && _gamePresentation.getSatellitePresentationVector().size() == 0 && timer > 0) {
             
            _gamePresentation.gameLogic_shared_pointer->createSatellites();
             
            _gamePresentation.createSatellitePresenetation();
            

        }
        //Fires a bullet from the satellite every few seconds
        if(timer%255 == 0 && _gamePresentation.getSatellitePresentationVector().size()>0){
            
            _gamePresentation.gameLogic_shared_pointer->fireSatelliteBulletLogic();
            
            _gamePresentation.createSatelliteBulletPresentation();
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

        updatePlayer();

        updateAllEnemies();

        _window.clear(sf::Color::Black);
        renderCharacters(_window);
        _window.display();

        timer++;
    }

    std::cout << _gamePresentation.getEnemyPresentationVector().size() << std::endl;
}

void GameWindow::renderCharacters(RenderWindow& window)
{

    _gamePresentation.drawAllBullets(window);
    _gamePresentation.drawAllEnemies(window);
    _gamePresentation.renderSprite(window);
    _gamePresentation.drawSatellites(window);
    _gamePresentation.drawSatelliteBullets(window);
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
    _gamePresentation.gameLogic_shared_pointer->checkBulletScope();
    _gamePresentation.gameLogic_shared_pointer->playerBulletUpdate();
    _gamePresentation.upDatePlayerBulletPresentation();
    _gamePresentation.setPlayerLifeCount();
}

void GameWindow::updateAllEnemies()
{
    _gamePresentation.gameLogic_shared_pointer->updateEnemyLogic();
     _gamePresentation.updateEnemyPresentation();
     _gamePresentation.gameLogic_shared_pointer->checkEnemyScope();
    _gamePresentation.deleteDeadEnemies();
    _gamePresentation.gameLogic_shared_pointer->updateSatelliteLogic();
    _gamePresentation.gameLogic_shared_pointer->checkSatelliteBulletScope();
}
