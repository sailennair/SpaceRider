#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "GamePresentation.h"
#include "GameLogic.h"
#include "GameCommonData.h"
#include <vector>
#include <memory>
#include "IntroductionWindow.h"
#include "FinalWindow.h"
#include "ExplosionPresentation.h"
#include <SFML/Graphics.hpp>

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

using namespace sf;

//! Game Window class - creates a gamw window and runs the game in sequence.
/*! This class runs the game in sequence and renders all the game objects onto the scree.
\author Sailen Nair and William Becerra
 *
*/

class GameWindow
{

public:
    /**Default constructor, creates an object of 'GamePresentation'
     */
    GameWindow();

    /**Checks the direction the user is commanding the player to move and sends it back to the logic domain
     */
    void checkKeyBoardEvent();

    /**This function creates the game window and creates all the enemies at certain time intervals.
     * The game window is created in this function. All the enemies are called to spawn after certain time intervals.
     * The method
     * polls input from the user and then will update the screen. The input can move and fire bullets. The collision
     * method from 'GameLogic' is called and all collsions are checked.
     * Once all the collisions are checked the player as well as all the enemies are updated.
     * All the characters are then displayed onto the screen. IF all the enemies have been killed then the game has been
     * completed and the game window closes.
     *
     */
    void generateWindow();

    /**Draws all the characters onto the window.
     * This fucntion will call all the draw functions in the presentaion domain to draw the characters onto the screen.
     * @param window
     */
    void renderCharacters(RenderWindow& window);

    /**Method will tell the logic domain to create a bullet.
     * This method is called when the player presses space bar.
     */
    void firePlayerBullet();

    /**Calls methods to update the player position, score and bullets.
     * The method will tell the presentation layer to update position so it can be drawn in the new position.
     */
    void updatePlayer();

    /**This method is called to update all the enemies of the game.
     * The method will update the position and presentation of all the enemeies and their respective bullets.
     */
    void updateAllEnemies();

    /**This method runs the introduction splash screen, the actual game window and the ending splash screen.
     */
    void runGame();

private:
    GamePresentation _gamePresentation;

    RenderWindow _window;

    Direction _direction;

    IntroductionWindow introductionWindow;

    FinalWindow finalWindow;
};

#endif // GAMEWINDOW_H
