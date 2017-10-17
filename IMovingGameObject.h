#ifndef IMOVINGGAMEOBJECT_H
#define IMOVINGGAMEOBJECT_H

#include <vector>
#include <map>
#include <utility>
#include "GameCommonData.h"

#define PI 3.14159265

//! Interface class resposible for creating characteristics of a movable object model.
/*! This class is responsible for been a role model class to movable objec that objects inherit a contract to adhere.
\author Sailen Nair and William Becerra
 *
*/

class IMovingGameObject
{
public:

/** Returns true if a movable object's health is greater than zero.
 *  All objects have a health this is simply a usefull model to determine if a movable object should be drawin in screen.
 * @return boolean true if player alive.
 */    
    virtual bool isAlive() = 0;
    
 /** Returns x co-ordinate of the movable object's current position.
 * All movable object's move and therefore have changing positions
 * @return float containing movable object's x co-ordinate position.
 */   
    virtual float getXposition() = 0;
    
 /** Returns y co-ordinate of the movable object's current position.
 * All movable object's move and therefore have changing positions
 * @return float containing movable object's y co-ordinate position.
 */   
    virtual float getYposition() = 0;
    
/** Returns the radius of a movable object.
 * Although a  movable object is not necesserally circular a radius is defined from the center to the edges of the object. This is usefull for collision detection.
 * @return float containing  movable object's radius.
 */ 
    virtual float getRadius() = 0;
    
/** Returns the center x co-ordinate of the movable object's current position.
 *  @see getCenterYPosition().
 *  @return float containing movable object's x co-ordinate of the center.
 */       
    virtual float getCenterXPosition() = 0;
 
 /** Returns the center y co-ordinate of the movable object's current position.
 *  @see getCenterXPosition().
 *  @return float containing movable object's y co-ordinate of the center.
 */    
    virtual float getCenterYPosition() = 0;

};

#endif // IMOVINGGAMEOBJECT_H
