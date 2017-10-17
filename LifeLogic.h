#ifndef LIFELOGIC_H
#define LIFELOGIC_H

//! Contols the logic of the players life
/*! This class is responsible for controlling the live of the player as well as its properties,
 * \author Sailen Nair and William Becerra
 *
*/
class LifeLogic
{
public:
/** Default construct.
 */
    LifeLogic();

/** Constructor Initializes LifeLogic instance.
 * @param x float containing the x co-ordinate to initilise the LifeLogic.
 * @param y float containing the y co-ordinate to initilise the LifeLogic.
 */
    LifeLogic(float x, float y);

/** Returns the x co-ordinate of the LifeLogic current position.
 * @return float containing the x co-ordinate of the LifeLogic.
 */
    float getXpos() const;

/** Returns the y co-ordinate of the LifeLogic current position.
 * @return float containing the y co-ordinate of the LifeLogic.
 */
    float getYpos() const;

/** Sets the postion of the LifeLogic instance to a position given by the parameters.
 * @param x float containing the x co-ordinate of the LifeLogic.
 * @param y float containing the y co-ordinate of the LifeLogic
 */ 
    void setPosition(float x, float y);

/**  Gets the number of lives left out 5 fives.
 * This function take in the the health status of the player and calulates how many lives left  
 * @param health integer containing the health of the player.
 * @return integer containing number of lives left.
 */
    int getNumberOfLivesRemaining(int health);

private:
    float _xpos;

    float _ypos;
};

#endif