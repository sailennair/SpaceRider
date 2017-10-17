#ifndef IPLAYER_H
#define IPLAYER_H

#include "IMovingGameObject.h"

//! Interface class resposible for creating characteristics of a Player model.
/*! This class is responsible for been a role model class to Player ensuring that Player created adhere to a contract.
\author Sailen Nair and William Becerra
 *
*/
class IPlayer: public IMovingGameObject
{
public:
/** Moves Player x co-oridnate in a circular motion to the left. 
 * All players have to move according to the same algorithm.
 * The circular movement keeps the same distance from the center of the screen.
 */
    virtual void moveLeftX() = 0;
/** Moves Player y co-oridnate in a circular motion to the left. 
 * All players have to move according to the same algorithm.
 * The circular movement keeps the same distance from the center of the screen.
 */
    virtual void moveLeftY() = 0;
/** Moves Player x co-oridnate in a circular motion to the right. 
 * All players have to move according to the same algorithm.
 * The circular movement keeps the same distance from the center of the screen.
 */
    virtual void moveRightX() = 0;
/** Moves Player y co-oridnate in a circular motion to the right. 
 * All players have to move according to the same algorithm.
 * The circular movement keeps the same distance from the center of the screen.
 */
    virtual void moveRightY() = 0;

/** Returns true if the player is health is greater than zero.
 *  All player have a health
 * @return boolean true if player alive.
 */
    virtual bool isAlive() = 0;
/** Returns x co-ordinate of the player's current position.
 * All players move and therefore have changing positions
 * @return float containing players x co-ordinate position.
 */
    virtual float getXposition() = 0;
/** Returns y co-ordinate of the player's current position.
 * All players move and therefore have changing positions
 * @return float containing players y co-ordinate position.
 */
    virtual float getYposition() = 0;

/**  Subtructs a damge amount from the players health.
 *  All player's have a health which is damaged by the different obstacles of the game.
 * @param _damage this sets a damage amount to be subtructed from the players health.
 */
    virtual void reduceHealth(int _damage) = 0;

/** Returns the angle of the player's current position from the players starting position.
 *  All players move in a gyration pattern meaning at different positions it will have differnt angles.
 * @return float containing players current angle.
 */
    virtual float getTheta() = 0;
/** Moves the player left or right for depending on user input.
 * A player moves depending on the user input. Accornding to the user input the correct move function is called.
 * @param dir Direction strongly typed enum class.
 *  @see moveLeftX().
 *  @see moveLeftY().
 *  @see moveRightY().
 *  @see moveRightX().
 */
    virtual void playerMove(Direction dir) = 0;
    
/** Returns the radius of the player.
 * Although a player is not circular a radius is defined from the center to the edges of the player. This is usefull for collision detection.
 * @return float containing players radius.
 */  
    virtual float getRadius() = 0;
/** Returns the center x co-ordinate of the player's current position.
 *  @see getCenterYPosition().
 *  @return float containing player's x co-ordinate of the center.
 */    
     virtual float getCenterXPosition() = 0;
/** Returns the center y co-ordinate of the player's current position.
 * @see getCenterXPosition().
 * @return float containing player's y co-ordinate of the center.
 */    
    virtual float getCenterYPosition() = 0;
};

#endif // IPLAYER_H
