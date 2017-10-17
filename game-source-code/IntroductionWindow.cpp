#include "IntroductionWindow.h"
#include <iostream>

IntroductionWindow::IntroductionWindow()
{
}

void IntroductionWindow::closeWindow(){
    _window.close();
}

void IntroductionWindow::createWindow()
{
    _window.create(sf::VideoMode(GameXWindow, GameYWindow), "Gyruss-Intro");
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
}
void IntroductionWindow::settingUpText()
{

    if(!_font.loadFromFile("sansation.ttf")) {
        std::cerr << "Error Loading the SplashWindow font";
    }

    _instructionText.setFont(_font);
    _instructionText.setString("\t\t\tINSTRUCTIONS \n"
                               "Press D for anti-clockwise rotation \n"
                               "Press A for clockwise Rotations \n"
                               "Press Spacebar to shoot");
    _instructionText.setCharacterSize(15);
    _instructionText.setPosition(20, 200);
    _gameRulesText.setFont(_font);
    _gameRulesText.setString("\t\t\t\tGAME RULES \n"
                             "1) Shoot Enemy Aircraft, Satellites\n and Laser Generators To score Points \n"
                             "2) Collisions Result in Death \n"
                             "3) Avoid Enemy Bullets \n");

    _gameRulesText.setCharacterSize(15);
    _gameRulesText.setPosition(500, 200);

    _continuePrompt.setFont(_font);
    _continuePrompt.setString("To CONTINUE to the Game Press SPACEBAR \n"
                              "\t\t\t\t To QUIT press ESC");
    _continuePrompt.setCharacterSize(20);
    _continuePrompt.setPosition(220, 450);
    
    
    if(!_logoTexture.loadFromFile("SpaceRider.PNG")) {
        std::cerr << "Error Loading logo Texture";
    }
    _logoTexture.setSmooth(true);
    _logo.setTexture(_logoTexture);
    _logo.setScale(sf::Vector2f(0.5, 0.5));
    _logo.setPosition(CenterXGameWindow - 150, 10);
}

void IntroductionWindow::run()
{
    ExplosionPresentation explosion(CenterXGameWindow, CenterYGameWindow);
    createWindow();
    settingUpText();
   
    while(_window.isOpen()) {

        sf::Event event;
        while(_window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {
                _isPlayerQuiting = true;
                _window.close();
                break;
            }

            if(event.type == sf::Event::KeyPressed) { // Need to check this because mouse was been picked up as input
                hadleUserDecision(event);
            }
        }

        _window.clear(sf::Color::Black);
        _window.draw(_instructionText);
        _window.draw(_gameRulesText);
        _window.draw(_continuePrompt);
        _window.draw(_logo);
        explosion.draw(_window);
        _window.display();
    }
}

bool IntroductionWindow::isQuitingGame()
{
    return _isPlayerQuiting;
}

void IntroductionWindow::hadleUserDecision(const sf::Event& event)
{
    if(event.key.code == sf::Keyboard::Space) {
        _continueOrQuitText.setFont(_font);
        _continueOrQuitText.setString("Good Luck Player");
        _continueOrQuitText.setCharacterSize(24);
        _continueOrQuitText.setPosition(300, 250);

        _window.clear(sf::Color::Black);
        _window.draw(_continueOrQuitText);
        _window.draw(_logo);
        _window.display();

        sf::sleep(sf::milliseconds(1500));
        _isPlayerQuiting = false;
        _window.close();
    }

    if(event.key.code == sf::Keyboard::Escape) {
        _continueOrQuitText.setFont(_font);
        _continueOrQuitText.setString("Good Bye See You Soon");
        _continueOrQuitText.setCharacterSize(24);
        _continueOrQuitText.setPosition(280, 250);

        _window.clear(sf::Color::Black);
        _window.draw(_continueOrQuitText);
        _window.draw(_logo);
        _window.display();

        sf::sleep(sf::milliseconds(1500));
        _isPlayerQuiting = true;
        _window.close();
    }
}