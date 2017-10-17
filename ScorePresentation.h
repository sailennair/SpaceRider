#ifndef SCOREPRESENTATION_H
#define SCOREPRESENTATION_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

//! Controls the presentation of the score system.
/*! This class is responsible for controlling the score system's graphical representation.
\author Sailen Nair and William Becerra
 *
*/


class ScorePresentation{
public:
/** Default constructor inititalise the score font, position and default scale.
 */
    ScorePresentation();
/** Constructor inititalise the score font, position and default scale.
 * The highest score is set to the value of the parameter.
 * @param highestScore integer containing the highest score
 */  
    ScorePresentation(int highestScore);
/** Draws the score system Text.
 * @param window to draw the score system.
 * @param x float containing the x co-ordinate to draw score system.
 * @param y float containing the y co-ordinate to draw score system.
 */
    void draw(sf::RenderWindow& window , float x, float y);
    
/** Sets the Messegage of the highest score to be displayed in a window 
 */
    void setScoreMessage(int highestScore);

private:
    sf::Font _scoreFont;
    sf::Text _scoreText;
    std::string _scoreMessage;

};

#endif