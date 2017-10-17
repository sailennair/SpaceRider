#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "IBullet.h"
#include "PlayerLogic.h"

//! Player bullet Class - contols the logic of the bullet of the player.
/*! This class is responsible for controlling the movement of the player bullet as well as its properties,
 * such as its damage. This class also controls the bullet life.
\author Sailen Nair and William Becerra
 *
*/

class PlayerBullet : public IBullet
{
public:
/** Constructor Initializes the Player bullets position, angle of direction and the the type of bullet.
 * @param xPosition float containing the x co-ordinate to initilise the bullet.
 * @param yPosition float containing the y co-ordinate to initilise the bullet.
 * @param theta float containing the direction the bullet should move towards.
 * @param type integer that the defines the type of bullet.
 */
    PlayerBullet(int xPosition, int yPosition, float theta, int type);
/**
 * @brief Moves the bullet in the direction defined by the angle of direction
 */
    void move();
/**
 * @brief Sets the damage that the bullet makes to an Enemy's health
 * @param damage integer containing the damage amount
 */
   void setDamage(int damage);
/**
 * @brief Gets the damage amount that the bullet makes to an enemy. 
 * @return integer containing the damage amount
 */    
    int getDamage();
/**
 * @brief Returns the life status of a bullet.
 * A bullets alive is defined by collisions. If a bullet has not collided its alive and if it has then it is dead.
 * @return boolean contatning the life status of the bulllet
 */
    bool isAlive();
/**
 * @brief Returns the x co-ordinate of the bullets current position
 * @return float containing the x co-ordinate of the bullet
 */
    float getXposition();
/**
 * @brief Returns the y co-ordinate of the bullets current position
 * @return float containing the y co-ordinate of the bullet
 */
    float getYposition();
/**
 * @brief Sets the life status of the bullet
 * @see isAlive()
 * @param life boolean containing the life status the bullet should be set to. 
 */
    void setLife(bool life);
/**
 * @brief Moves the bullet in the direction of the initialized angle 
 */
    void fire();
/**
 * @brief Gets the raidus of the bullet
 * @return integer containing the radius of the bullet
 */
    float getRadius();
/**
 * @brief Gets the x co-ordinate of the center of the bullet
 * @return float containing the x co-orindate of the center of the bullet
 */
    float getCenterXPosition();
/**
 * @brief Gets the y co-ordinate of the center of the bullet
 * @return float containing the y co-orindate of the center of the bullet
 */
    float getCenterYPosition();

private:

float _theta;
    int _playerBulletXposition;
    int _playerBulletYposition;
    int _speedOfBullets = 15;
    int _damage = 5;
    bool _isAlive = true;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
};

#endif // PLAYERBULLET_H