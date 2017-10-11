#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameCommonData.h"

using namespace sf;

class FinalWindow
{
public:
    FinalWindow();

    bool isPlayerQuittingGame(); // Returns true if player decides to quite the game
    bool didPlayerLoseGame();    // Returns true if the player lost the game

    // This function set whether the player lost or is quitting the game
    void setQuittingGame(bool decision);
    void setPLayerLostGame(bool status);

    // This function runs the window loop and logic
    void run();
    void closeWindow();

private:
    // This function just loads the text and all the graphics. The purpose is to divide the resposibility and neaten up
    // code
    void setUpWindow();
    void loadText();
    // Hnadles user input
    void hadleUserDecision(const Event& event);

    // Player Status and Decision variables
    bool _isPlayerQuitting;
    bool _didPlayerLose;

    // Messages to display
    Text _playerLostOrWonMessage;
    Text _continueOrQuitMessage;
    Text _prompUserToContinue;

    // Font used for the text in these window
    Font _font;

    // The sfml-window
    RenderWindow _window;

    // Window Dimensions
    unsigned int _width;
    unsigned int _height;
};

#endif