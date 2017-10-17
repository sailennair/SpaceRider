#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H

#include "EnemyBulletLogic.h"

#include "GameCommonData.h"
#include "math.h"
#include <iostream>
#include "IEnemy.h"

//! Enemy Logic Class - contols the logic of the main enemies.
/*! This class is responsible for controlling the movement and the life of the main enemies.
\author Sailen Nair and William Becerra
 *
*/

class EnemyLogic : public IEnemy
{
public:
/**
 * @brief Constructor intitializes the enemy to position and a direction angle.
 * @param initalXposition the x-cordinate of initial position.
 * @param initalYposition the y-cordinate of initial position.
 * @param theta the angle of direction the enemy moves to.
 */
    EnemyLogic(int initalXposition, int initalYposition, float theta);
/**
 * @brief Moves the enemy in the direction of the angle it is initialized to.
 */
    void move();
/**
 * @brief Returns the angle of rotation of the enemy.
 * @return float containing the angle of rotation of the enemy.
 */
    float getAngleofRotation();    
/**
 * @brief Returns true if the enemy's health is greater than zero.
 * @return boolean constaining life status of the enemy.
 */
    bool isAlive();
/**
 * @brief Decreases the health of the enemy by an amount given by the parameteter.
 * @param _damage interger containing the amount that the health should be decreased by.
 */
    void reduceHealth(int _damage);
/**
 * @brief Returns the x co-ordinate of the enemy.
 * @return float containing the x co-ordinate of the enemy.
 */
    float getXposition();
/**
 * @brief Returns the y co-ordinate of the enemy.
 * @return float containing the y co-ordinate of the enemy
 */
    float getYposition();
/**
 * @brief Sets the enemy's life status to dead or alive according to the parameter
 * @param life boolean describing the life status the enemy should be set to
 */
    void setLife(bool life);
/** Returns the outOfBounds status of the enemy.
 * outOfBounds is defined by the enemy moving outside of the screen.
 * @see setOutofBounds(bool outOfBounds).
 * @return boolean containing the outOfBounds status of the enemy.
 */
    bool isOutOfBounds();
/** Sets the outbounds status of the enemy to the outOfBounds parameter.
 * outOfBounds is defined by the enemy moving outside of the screen.
 * @see isOutOfBounds().
 * @param outOfBounds boolean containing enemy's out of bounds status.
 */  
    void setOutofBounds(bool outOfBounds);
/**
 * @brief Moves the enemy to the centerPosition of the screen and sets the angle of direction for the enemy to move
 * @param xPosition the x co-ordinate of the center of the screen.
 * @param yPosition the y co-ordinate of the center of the screen.
 * @param theta the angle of direction for enemy to move when its respawend.
 */
    void moveToCenter(float xPosition, float yPosition, float theta);
/**
 * @brief Returns the radius of the enemy.
 * @return float containing enemy's radius.
 */    
    float getRadius();
 /**
 * @brief Returns the center x co-ordinate of the enemy's current position.
 * @return float containing enemy's x co-ordinate of the center.
 */   
    float getCenterXPosition();
 /**
 * @brief Returns the center y co-ordinate of the enemy's current position.
 * @return float containing enemy's y co-ordinate of the center.
 */   
    float getCenterYPosition();
/**
 * @brief Sets the enemy's Speed.
 * @return float containing speed of the enemy.
 */     
    void setEnemySpeed(float speed);
/**
 * @brief Sets the enemy's radius.
 * @param radius of the enemy.
 */    
    void setRadius(int radius);
/**
 * @brief Returns a vector of type EnemyBulletLogic.
 * @return EnemyBulletLogic containing the bullets the enemy fires
 */
    std::vector<EnemyBulletLogic> getEnemyBulletLogicVector();
/**
 * @brief Clears the EnemyBulleVector
 */
    void clearEnemyBulletVector();
/**
 * @brief Sets the enemy bullets life to alive or dead.
 * A bullets life is defined to be dead after collision and alive if it hasnt collided with a game object
 * @param life boolen containing the life status of the bullet
 */
    void setEnemyBulletLife(bool life);


private:
std::vector<EnemyBulletLogic> enemyBulletLogicVector;

     int enemySize = 20;
    float _xpos;
    float _ypos;
    float _theta;
    bool _isAlive = true;
    int _health = 15;
    int _initialXposition;
    int _initialYposition;
    float _enemySpeed = 0.005;
    bool _outOfBounds = false;
    float _centerXPosition;
    float _centerYPosition;
    float _radius;

};

#endif // ENEMYLOGIC_H