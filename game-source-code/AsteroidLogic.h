#ifndef ASTEROIDLOGIC_H
#define ASTEROIDLOGIC_H

#include "GameCommonData.h"
#include "math.h"
#include <iostream>
#include "IEnemy.h"

//! Contols the logic of a Asteroid.
/*! This class is responsible for controlling the movement a Asteroid.
\author Sailen Nair and William Becerra
 *
*/
class AsteroidLogic : public IEnemy
{
public:
/** Construtor initializes the Asteroid at the center of the screen.
 * @param theta definines the direction the asteroid moves towards.
 */
    AsteroidLogic(float theta);
/** Moves the asteroid in a straight line in the direction given by the angle the asteroid was intialised to.
 */
    void move();

    float getAngleofRotation();
/** Returns true if the asteroid's health is greater than zero.
 * @see decreaseHealth(int damage).
 * @return boolean true if asteroid alive.
 */
    bool isAlive();
/** Subtructs a damge amount from the asteroid health.
 * @param damage sets a damage amount to be subtructed from the asteroid health.
 */
    void reduceHealth(int _damage);
/** Returns the x co-ordinate of the asteroid.
 * @see  getYposition()
 * @return float containing the x co-ordinate of the asteroid
 */
    float getXposition();
/** Returns the y co-ordinate of the asteroid.
 * @see  getXposition()
 * @return float containing the y co-ordinate of the asteroid
 */   
    float getYposition();
/** Sets the asteroid's alive status to dead or alive.
 * @param boolean life status. false to set asteroid to dead.
 */
    void setLife(bool life);
/** Returns the radius of the asteroid.
 * @return float containing asteroid radius.
 */
    float getRadius();
/** Returns the center x co-ordinate of the asteroid's current position.
 * @see getCenterYPosition().
 * @return float containing asteroid's x co-ordinate of the center.
 */
    float getCenterXPosition();
/** Returns the center y co-ordinate of the asteroid's current position.
 * @see getCenterXPosition().
 * @return float containing asteroid's y co-ordinate of the center.
 */
    float getCenterYPosition();
/** Sets the outbounds status of the asteroid to the outOfBounds parameter.
 *  outOfBounds is defined by the asteroid moving outside of the screen.
 * @see isOutOfBounds().
 * @param outOfBounds boolean containing asteroid's out of bounds status.
 */  
    void setOutOfBounds(bool bounds);
/** Returns the outOfBounds status of the asteroid.
 * outOfBounds is defined by the asteroid moving outside of the screen.
 * @return boolean containing the outOfBounds status of the asteroid.
 */
    bool isOutOfBounds();
/** Returns the damage value an asteroid does to a player if there is a collision.
 * @return float containing the damage value an asteroid can do to a player.
 */
    float getDamage();

private:
    float _xpos;
    float _ypos;
    float _theta;
    bool _isAlive;
    int _health;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed;
    bool _outOfBounds;
    int _asteroidSize;
    float _centerXPosition;
    float _centerYPosition;
    float _radius;
    float _damage;
};

#endif // ASTEROIDLOGIC_H
