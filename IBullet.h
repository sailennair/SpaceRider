#ifndef IBULLET_H
#define IBULLET_H

#include "IMovingGameObject.h"
//! Interface class resposible for creating characteristics of a bullet model.
/*! This class is responsible for been a role model class to bullets ensuring that bullets created adhere to a contract.
\author Sailen Nair and William Becerra
 *
*/
class IBullet : public IMovingGameObject
{
public:
/** Moves the bullet.
 * All bullets need to be fired and have the ability to move.
 */
    virtual void move() = 0;

/** Gets the damage amount that the bullet makes to a target.
 *  All bullets have differnt power and can cause different damage on a target 
 * @return integer containing the damage amount
 */    
    virtual int getDamage() = 0;

/** Returns the life status of a bullet.
 * A bullets alive is defined by collisions. If a bullet has not collided its alive and if it has then it is dead.
 * This definition is helpful to be determine when a bullet should be drawn or not.
 * @return boolean contatning the life status of the bulllet
 */
    virtual bool isAlive() = 0;

/** Returns the x co-ordinate of the bullets current position.
 *  All bullets move and therefore have a position in the screen that can change.
 * @return float containing the x co-ordinate of the bullet.
 * @see getYposition()
 */
    virtual float getXposition() = 0;
    
/** Returns the y co-ordinate of the bullets current position.
 * All bullets move and therefore have a position in the screen that can change.
 * @return float containing the y co-ordinate of the bullet.
 * @see getXposition().
 */
    virtual float getYposition() = 0;

/** Sets the life status of the bullet.
 * @see isAlive()
 * @param life boolean containing the life status the bullet should be set to. 
 */

    virtual void setLife(bool life) = 0;

/** Gets the raidus of the bullet.
 * All bullets are round in shape and have a radius associated with them.
 * @return integer containing the radius of the bullet
 */
    virtual float getRadius() = 0;

/** Gets the x co-ordinate of the center of the bullet
 * @return float containing the x co-orindate of the center of the bullet
 */
    virtual float getCenterXPosition() = 0;
/**  Gets the y co-ordinate of the center of the bullet
 * @return float containing the y co-orindate of the center of the bullet
 */
    virtual float getCenterYPosition() = 0;
};

#endif // IBULLET_H
