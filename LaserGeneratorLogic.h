#ifndef LASERGENERATORLOGIC_H
#define LASERGENERATORLOGIC_H
#include "GameCommonData.h"
#include "EnemyLogic.h"
#include "EnemyBulletLogic.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <time.h>
#define PI 3.14159265

//! Laser Generator class - controls the logic of the laser generator.
/*! This clas controls the logic of the laser generator which includes enemies and enemy bullets
\author Sailen Nair and William Becerra
 *
*/
class LaserGeneratorLogic
{
public:
    /**Default constructor that creates the components of the laser generator.
     * The laser generator is comprised of two enemies and 20 enemy bullets, their movement speeds are set so that they
     * all move in sync.
     * The laser generator can be moved in two directions. The direction is chosen randomly when the constructor is
     * called. All the enemy bullets damage is set to 0,
     * this allows for the player to not be colliding with multiple bullets at the same time. The angles of the enemies
     * are set to allow a gap for the bullets
     * to be seen.
     */

    LaserGeneratorLogic();
    /**Updates the movement of the laser generator.
     * This functionw will call the move function for the enemies and the enemyBullet. This ensures the enemy and enemy
     * bullets move at the same time at the same rate.
     */
    void move();
    /**Method will decrease the health of one of the laser generator enemies.
     * The laser generator stored at position 'index' in the the laserGeneratorEnemyLogicVector will get its health
     * reduced by an integer value of 'damage'/
     * @param index - the laser generator that will have its health decreased.
     * @param damage - the amount that the laser generator health will be reduced by.
     */
    void reduceHealthOfGenerator(int index, int damage);

    /**Sets the life of the laser Generator to either true or false.
     * @param index - laser generator to be affected.
     * @param life - setting the laser generator to either 'true' or 'false'.
     */
    void setGeneratorEnemyLife(int index, bool life);

    /**Returns a vector of type 'EnemyLogic' with the two laser generator enemies storred within.
     * @return - returns a vector of type 'EnemyLogic'
     */
    std::vector<EnemyLogic> getLaserGeneratorEnemyLogicVector();

    /**Returns a vector of type 'EnemyBulletLogic' with all the laser bullets storred within.
     * @return Returns a vector of type 'EnemyBulletLogic'
     */
    std::vector<EnemyBulletLogic> getLaserGeneratorBulletLogicVector();

private:
    std::vector<EnemyLogic> _laserGeneratorEnemyLogicVector;

    std::vector<EnemyBulletLogic> _laserGeneratorEnemyBulletLogicVector;

    float _theta;

    int _randomNumber;
};

#endif // LASERGENERATORLOGIC_H
