#ifndef ENEMYBULLETPRESENTATION_H
#define ENEMYBULLETPRESENTATION_H

#include <SFML/Graphics.hpp>
#include "GameCommonData.h"

//! Controls the presentation of the Enemy Bullets.
/*! This class is responsible creating the Enemy Bullet sprite and putting it at a position on the screen.
\author Sailen Nair and William Becerra
 *
*/
class EnemyBulletPresentation
{
public:
/** Default constructor Inititalises the Enemy Bullets.
 *  Initilizes the Bullet to a fill color red and a radius of 10.  
 */
    EnemyBulletPresentation();
 /** Constructor Initialises the enemy bullet at a position given by the parameter
  *  @param xPosition float containing the x co-ordinate the bulllet to intialize the bullet
  *  @param yPosition float containing the y co-ordinate the bulllet to intialize the bullet
  */ 
    EnemyBulletPresentation(float xPosition , float yPosition);
/** Draws the enemy bullet sprite.
 *  @param window to draw the nemy bullet on.
 */  
    void draw(sf::RenderWindow &window);
/** Updates the enemy bullet sprite position as the bullet moves.
  *  @param xPosition float containing the x co-ordinate the bulllet has moved to.
  *  @param yPosition float containing the y co-ordinate the bulllet has moved to.
  */
    void updateEnemyBullet(float xPosition , float yPosition);
/** Returns the enemy bullet sprite.
 *  @return  Sfml Circle shape containing the graphical representation of the enemy bullet
 */
    sf::CircleShape getEnemyBullet();
   
   
private:

  sf::CircleShape _enemyBullet;
};

#endif // ENEMYBULLETPRESENTATION_H
