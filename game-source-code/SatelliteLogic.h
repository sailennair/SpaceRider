#ifndef SATELLITELOGIC_H
#define SATELLITELOGIC_H

#include <math.h>
#include "IMovingGameObject.h"
#include "EnemyBulletLogic.h"

//! Contols the logic of a Satellite.
/*! This class is responsible for controlling the movement and the life a Satellite.
\author Sailen Nair and William Becerra
 *
*/

class SatelliteLogic : public IMovingGameObject
{
public:
    /** Default Constructor intitializes the Satellite to position and an angle of rotation.
     * @param x the x-cordinate of initial position.
     * @param y the y-cordinate of initial position.
     * @param theta the angle of rotation the Satellite.
     */
    SatelliteLogic(float x, float y, float theta);
    /** Moves the Satellite in the rotational movement.
     *  The a rate of rotation given by the angle of rotation the satellite is initialized to.
     */
    void move();
    /** Returns the x co-ordinate of the Satellite.
     * @see  getYposition()
     * @return float containing the x co-ordinate of the Satellite
     */
    float getXposition();
    /** Returns the y co-ordinate of the Satellite.
     * @see  getXposition()
     * @return float containing the y co-ordinate of the Satellite
     */
    float getYposition();
    /** Returns true if the Satellite's health is greater than zero.
     * @see decreaseHealth(int damage).
     * @return boolean true if Satellite alive.
     */
    bool isAlive();
    /** Subtructs a damge amount from the Satellite health.
     * @param damage sets a damage amount to be subtructed from the Satellite health.
     */
    void decreaseHealth(int damage);
    /** Returns the radius of the Satellite.
     * @return float containing Satellite radius.
     */
    float getRadius();
    /** Returns the center x co-ordinate of the Satellite's current position.
     * @see getCenterYPosition().
     * @return float containing Satellite x co-ordinate of the center.
     */
    float getCenterXPosition();
    /** Returns the center y co-ordinate of the Satellite's current position.
     * @see getCenterXPosition().
     * @return float containing Satellite y co-ordinate of the center.
     */
    float getCenterYPosition();

private:
    float _xPos;

    float _yPos;

    float _spawnedXpos;

    float _spawnedYpos;

    float _angleOfRotation; // This will essentially be the speed of rotation

    int _health;

    float _radius;

    float _centerXPosition;

    float _centerYPosition;

    int _radiusOfRotation;
};

#endif