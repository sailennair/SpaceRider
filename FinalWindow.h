#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameCommonData.h"

//! Creates a  final game window.
/*! Generates and appropiate message for the player and promps the player for a replay
\author Sailen Nair and William Becerra
 *
*/

class FinalWindow
{
public:
/** Default constructor.
 * Loads all the graphics and text rendering of the final window.
 */
    FinalWindow();
/** Returns true if player decided to quite game
 * @return boolean true for player quiting the game
 */
    bool isPlayerQuittingGame();
    
/** Returns true if player lost game
 * @return boolean true for player losing the game
 */
    bool didPlayerLoseGame(); 

/** Setter function to set the players decision to quit the game.
 * @param decision boolean containing player's decision.
 */
    void setQuittingGame(bool decision);
    
/** Setter function to set the players losing game status.
 * @param status boolean containing player's losing game status.
 */    
    void setPLayerLostGame(bool status);

/** Void function that runs the window loop
 * waits for players input to act acordingly
 */
    void run();
/** Void function to close the FinalWindow.
 */
    void closeWindow();

private:


    // This function just loads the text and all the graphics. The purpose is to divide the resposibility and neaten up
    // code
    void setUpWindow();
    void loadText();
    // Hnadles user input
    void hadleUserDecision(const sf::Event& event);

    // Player Status and Decision variables
    bool _isPlayerQuitting;
    bool _didPlayerLose;

    // Messages to display
    sf::Text _playerLostOrWonMessage;
    sf::Text _continueOrQuitMessage;
    sf::Text _prompUserToContinue;

    // Font used for the text in these window
    sf:: Font _font;

    // The sfml-window
    sf::RenderWindow _window;

    // Window Dimensions
    unsigned int _width;
    unsigned int _height;
};

#endif