#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#define COLLISIONDETECTION_H 
 
#include "IMovingGameObject.h"  
 
class CollisionDetection 
{ 
public: 
    CollisionDetection(); 
     
    bool didObjectsCollide( IMovingGameObject& obj1,  IMovingGameObject& obj2);  
 
}; 
 
#endif // COLLISIONDETECTION_H 
