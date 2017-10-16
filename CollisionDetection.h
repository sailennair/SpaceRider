#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#define COLLISIONDETECTION_H 
 
#include "IMovingGameObject.h"  
 
 //!Checks if two objects of the game collide.
/*! This class is responsible for checking if two  moving objects of the game collide.
\author Sailen Nair and William Becerra
 *
*/
class CollisionDetection 
{ 
public: 
/**Defualt constructor, creates an object of 'Collision detection.
 */
    CollisionDetection(); 
     /**Checks if the two objects passed in the function has collided.
      * The two objects passed in are of both type 'IMovingGameObject', hence each object will have the same inherited methods.
      * The function will check if two objects have collided by getting the radius of each object and the center of co-ordinates of
      * each object. The function will then calculate the distance between the two objects and if that distance is less than the sum of two radi, then
      * the method will return true. This method makes use of the Pythagorean Theorem. 
      * @param obj1 - an object of type 'IMovingGameObject'
      * @param obj2 - an object of type 'IMovingGameObject'
      * @return true of objects collide, false if they dont
      */
    bool didObjectsCollide( IMovingGameObject& obj1,  IMovingGameObject& obj2);  
 
}; 
 
#endif // COLLISIONDETECTION_H 
