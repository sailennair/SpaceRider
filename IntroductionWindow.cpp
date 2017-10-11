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
    _window.create(VideoMode(GameXWindow, GameYWindow), "Gyruss-Intro");
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
                               "Press W or A for anti-clockwise rotation \n"
                               "Press S or D for clockwise Rotations \n");
    _instructionText.setCharacterSize(15);

    _gameRulesText.setFont(_font);
    _gameRulesText.setString("\t\t\t\tGAME RULES \n"
                             "1) Shoot Enemy Aircraft To score Points \n"
                             "2) Collisions Result in Death \n"
                             "3) Avoid Enemy Bullets \n");

    _gameRulesText.setCharacterSize(15);
    _gameRulesText.setPosition(500, 0);

    _continuePrompt.setFont(_font);
    _continuePrompt.setString("To CONTINUE to the Game Press SPACEBAR \n"
                              "\t\t\t\t To QUIT press ESC");
    _continuePrompt.setCharacterSize(20);
    _continuePrompt.setPosition(220, 250);
}

void IntroductionWindow::run()
{
    createWindow();
    settingUpText();
   
    while(_window.isOpen()) {

        Event event;
        while(_window.pollEvent(event)) {

            if(event.type == Event::Closed) {
                _window.close();
                break;
            }

            if(event.type == Event::KeyPressed) { // Need to check this because mouse was been picked up as input
                hadleUserDecision(event);
            }
        }

        _window.clear(Color::Black);
        _window.draw(_instructionText);
        _window.draw(_gameRulesText);
        _window.draw(_continuePrompt);
        _window.display();
    }
}

bool IntroductionWindow::isQuitingGame()
{
    return _isPlayerQuiting;
}

void IntroductionWindow::hadleUserDecision(const Event& event)
{
    if(event.key.code == Keyboard::Space) {
        _continueOrQuitText.setFont(_font);
        _continueOrQuitText.setString("Good Luck Player");
        _continueOrQuitText.setCharacterSize(24);
        _continueOrQuitText.setPosition(300, 250);

        _window.clear(Color::Black);
        _window.draw(_continueOrQuitText);
        _window.display();

        sleep(milliseconds(1500));
        _isPlayerQuiting = false;
        _window.close();
    }

    if(event.key.code == Keyboard::Escape) {
        _continueOrQuitText.setFont(_font);
        _continueOrQuitText.setString("Good Bye See You Soon");
        _continueOrQuitText.setCharacterSize(24);
        _continueOrQuitText.setPosition(280, 250);

        _window.clear(Color::Black);
        _window.draw(_continueOrQuitText);
        _window.display();

        sleep(milliseconds(1500));
        _isPlayerQuiting = true;
        _window.close();
    }
}