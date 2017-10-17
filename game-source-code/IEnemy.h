#ifndef IENEMY_H
#define IENEMY_H

#include "IMovingGameObject.h"

//! Interface class resposible for creating characteristics of a Enemy model.
/*! This class is responsible for been a role model class to Enemy ensuring that Enemy created adhere to a contract.
This class inherits from ImovingGameObject
\author Sailen Nair and William Becerra
 *
*/
class IEnemy : public IMovingGameObject
{
public:
    /** Moves the Enemy.
     * All bullets enemies have the ability to move.
     */
    virtual void move() = 0;
    /** Returns the angle of rotation of the enemy.
     * @return float containing the angle of rotation of the enemy.
     */
    virtual float getAngleofRotation() = 0;

    /** Returns true if the enemy's health is greater than zero.
     *  All enemies have a health that is decreased when a player object bullet hits the enemy
     * @return boolean constaining life status of the enemy.
     */
    virtual bool isAlive() = 0;
    /** Decreases the health of the enemy by an amount given by the parameteter.
     * Player objects can have different weapons with bullets that cause different damages.
     * @param _damage interger containing the amount that the health should be decreased by.
     */
    virtual void reduceHealth(int _damage) = 0;

    /** Returns the x co-ordinate of the enemy.
     *  All enemies move and therefore have cahnging positions.
     * @return float containing the x co-ordinate of the enemy.
     */
    virtual float getXposition() = 0;
    /** Returns the y co-ordinate of the enemy.
     *  All enemies move and therefore have cahnging positions.
     * @return float containing the y co-ordinate of the enemy.
     */

    virtual float getYposition() = 0;

    /** Sets the enemy's life status to dead or alive according to the parameter
     * @param life boolean describing the life status the enemy should be set to
     */
    virtual void setLife(bool life) = 0;

    /** Returns the radius of an enemy.
     * Although a  enemy is not necesserally circular a radius is defined from the center to the edges of the object.
     * This is usefull for collision detection.
     * @return float containing enemy's radius.
     */

    virtual float getRadius() = 0;

    /** Returns the center x co-ordinate of the enemy's current position.
    * @return float containing enemy's x co-ordinate of the center.
    */
    virtual float getCenterXPosition() = 0;

    /** Returns the center y co-ordinate of the enemy's current position.
    * @return float containing enemy's y co-ordinate of the center.
    */
    virtual float getCenterYPosition() = 0;
};

#endif // IENEMY_H
