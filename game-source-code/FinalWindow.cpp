#include "FinalWindow.h"

FinalWindow::FinalWindow(): 
    _width(GameXWindow),
    _height(GameYWindow)
{
}

void FinalWindow::closeWindow()
{
    _window.close();
}

// Sets up Window dimensions and Settings
void FinalWindow::setUpWindow()
{
    _window.create(sf::VideoMode(_width, _height), "Space Rider");
    _window.setMouseCursorVisible(false);
    _window.setVerticalSyncEnabled(true);
    if(!_logoTexture.loadFromFile("SpaceRider.PNG")) {
        std::cerr << "Error Loading logo Texture";
    }
    _logoTexture.setSmooth(true);
    _logo.setTexture(_logoTexture);
    _logo.setScale(sf::Vector2f(0.5, 0.5));
    _logo.setPosition(CenterXGameWindow - 150, 10);
}

// Loads Font
void FinalWindow::loadText()
{
    // Loading Font
    if(!_font.loadFromFile("sansation.ttf")) {
        std::cerr << "Error Loading the FinalWindwo font";
    }

    // PlayerLost Message set up
    _playerLostOrWonMessage.setFont(_font);
    int xPos = ((_width / 2) - 5 * (_prompUserToContinue.getCharacterSize()));
    _playerLostOrWonMessage.setCharacterSize(20);
    _playerLostOrWonMessage.setPosition(CenterXGameWindow - 130 , CenterYGameWindow);

    _continueOrQuitMessage.setFont(_font);

    _prompUserToContinue.setFont(_font);
    _prompUserToContinue.setString("To Continue Press SPACEBAR or To Quit Pess ESC");
    _prompUserToContinue.setCharacterSize(20);
    xPos = ((_width / 2) - 10 * (_prompUserToContinue.getCharacterSize()));
    int yPos = _height / 2 - 100;
    _prompUserToContinue.setPosition(xPos, yPos);
}

void FinalWindow::run()
{
    loadText();
    setUpWindow();
    while(_window.isOpen()) {

       sf::Event event;
        while(_window.pollEvent(event)) {

            if(didPlayerLoseGame()) {
                _playerLostOrWonMessage.setString("Sorry, You have Lost the Game");
            } else {
                _playerLostOrWonMessage.setString("   You have WON the Game!!   ");

            }

            if(event.type == sf::Event::KeyPressed) { // Need to check this because mouse was been picked up as input
                hadleUserDecision(event);
            }

            if(event.type == sf::Event::Closed) {
                _isPlayerQuitting = true;
                _window.close();
                break;
            }
        }

        _window.clear(sf::Color::Black);
        _window.draw(_prompUserToContinue);
        _window.draw(_playerLostOrWonMessage);
        _window.draw(_continueOrQuitMessage);
        _window.draw(_logo);
        _window.display();
    }
}

void FinalWindow::hadleUserDecision(const sf::Event& event)
{
    if(event.key.code == sf::Keyboard::Space) {
        _continueOrQuitMessage.setFont(_font);
        _continueOrQuitMessage.setString("    Good Luck Player!!    "); // The spaces are import to get the correct screen postion
        _continueOrQuitMessage.setCharacterSize(30);
        _continueOrQuitMessage.setPosition( CenterXGameWindow - 135 , CenterYGameWindow);
        

        _window.clear(sf::Color::Black);
        _window.draw(_continueOrQuitMessage);
        _window.draw(_logo);
        _window.display();

        sf::sleep(sf::milliseconds(1500));
        _isPlayerQuitting = false;
        _window.close();
    }

    if(event.key.code == sf::Keyboard::Escape) {
        _continueOrQuitMessage.setFont(_font);
        _continueOrQuitMessage.setString("   Good Bye See You Soon  ");
        _continueOrQuitMessage.setCharacterSize(24);
        _continueOrQuitMessage.setPosition(CenterXGameWindow - 135 , CenterYGameWindow);

        _window.clear(sf::Color::Black);
        _window.draw(_continueOrQuitMessage);
        _window.draw(_logo);
        _window.display();

        sf::sleep(sf::milliseconds(1500));
        _isPlayerQuitting = true;
        _window.close();
    }
}

/// STATUS QUERY FUNCTIONS
bool FinalWindow::isPlayerQuittingGame()
{
    return _isPlayerQuitting;
}

bool FinalWindow::didPlayerLoseGame()
{
    return _didPlayerLose;
}

/// STATUS SETTING FUNCTINOS
void FinalWindow::setQuittingGame(bool decision)
{
    _isPlayerQuitting = decision;
}

void FinalWindow::setPLayerLostGame(bool status)
{
    _didPlayerLose = status;
}
