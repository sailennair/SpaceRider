#ifndef ENEMYBULLETLOGIC_H
#define ENEMYBULLETLOGIC_H

#include "math.h"
#include "IBullet.h"


//! Contols the logic of the Enemy Bullets.
/*! This class is responsible for controlling the movement and the life of Enemy Bullets.
\author Sailen Nair and William Becerra
 *
*/
class EnemyBulletLogic : public IBullet
{
public:
/** Default Constructor intitializes the enemyBullet .
 */    
    EnemyBulletLogic();
/** Default Constructor intitializes the enemyBullet to position and a direction angle.
 * @param enemyXPosition the x-cordinate of initial position.
 * @param enemyYPosition the y-cordinate of initial position.
 * @param theta the angle of direction the bullet moves to.
 */   
    EnemyBulletLogic(float enemyXPosition, float enemyYPosition, float theta);
/** Moves the enemyBullet in the direction of the angle it is initialized to.
 */
    void move();
/** Returns the x co-ordinate of the bullet.
 * @return float containing the x co-ordinate of the bullet.
 */    
    float getXposition();
/**Returns the y co-ordinate of the bullet.
 * @see  getXposition()
 * @return float containing the y co-ordinate of the bullet
 */
    float getYposition();
/** Returns true if the bullet has collided with a IMovingGameObject.
 * @see  getXposition()
 * @return boolean constaining life status of the bullet.
 */
    bool isAlive() ;
/** Sets the damage that the bullet makes to the Players health.
 * @param damage integer containing the damage amount
 */
    void setDamage(int damage);
/** Gets the damage amount that the bullet makes to the player. 
 * @return integer containing the damage amount
 */ 
    int getDamage();
 /** Sets the life status of the bullet.
 * @see isAlive()
 * @param life boolean containing the life status the bullet should be set to. 
 */   
    void setLife(bool life);
/** Gets the raidus of the bullet
 * @return integer containing the radius of the bullet.
 */
    float getRadius();
/** Gets the x co-ordinate of the center of the bullet.
 * @see  getCenterYPosition()
 * @return float containing the x co-orindate of the center of the bullet
 */
    float getCenterXPosition();
/** Gets the y co-ordinate of the center of the bullet.
 *  @see  getCenterYPosition()
 * @return float containing the y co-orindate of the center of the bullet
 */    
    float getCenterYPosition();
/** Sets how fast the Enemy bullet should move.
 * @param speed float containing the speed the bullet.
 */
    void setBulletSpeed(float speed);

private:

    float _xPosition;
    float _yPosition;
    bool _isAlive = true;
    int _damage = 5;
    float _bulletSpeed = 0.015;
    float _theta;
    float _initialXposition;
    float _initialYposition;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
    
};

#endif // ENEMYBULLETLOGIC_H
