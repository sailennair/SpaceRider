#ifndef INTRODUCTIONWINDOW_H
#define INTRODUCTIONWINDOW_H

#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include "ExplosionPresentation.h"

//! Creates a  introduction game window.
/*! Generates and appropiate message for the player. This include instructions and game rules
 * Promps the player for to press space bar to continue
\author Sailen Nair and William Becerra
 *
*/

class IntroductionWindow
{
public:
/** Default constructor
 * Loads all the window graphics and textures
 */ 
    IntroductionWindow();
    
/** Void function contains the window loop.
 *  Is responsible for drawing all the graphics of the window and take in user input
 */
    void run();
    
/** Boolean function to return the players decision.
 *  @return bool true if the player decides to quit
 */    
    bool isQuitingGame();
/** Void function to close introduction window.
 */
    void closeWindow();

private:
    void createWindow();
    void settingUpText();
    void hadleUserDecision(const sf::Event& event);

    bool _isPlayerQuiting;

    sf::Font _font;

    sf::Text _instructionText;
    sf::Text _continueOrQuitText;
    sf::Text _continuePrompt;
    sf::Text _gameRulesText;
    
    sf::Sprite _logo;
    sf::Texture _logoTexture;
    
    sf::RenderWindow _window;
};

#endif