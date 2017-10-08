#include "CollisionDetection.h" 
 
CollisionDetection::CollisionDetection() 
{ 
} 
 
bool CollisionDetection::didObjectsCollide(IMovingGameObject& obj1, IMovingGameObject& obj2) 
{ 
 
    //    if((obj1.getXposition() + obj1.getWidth() >= obj2.getXposition()) && 
    //        (obj1.getYposition() + obj1.getHeight() <= obj2.getYposition())) { 
    //        return false; 
    //    } 
    //    return false; 
 
    float radius = obj1.getRadius() + obj2.getRadius(); 
 
    float temp = (obj1.getCenterXPosition() - obj2.getCenterXPosition()) * 
            (obj1.getCenterXPosition() - obj2.getCenterXPosition()) + 
        (obj1.getCenterYPosition() - obj2.getCenterYPosition()) * 
            (obj1.getCenterYPosition() - obj2.getCenterYPosition()); 
 
    if(temp < (radius * radius)) { 
        return true; 
    } else { 
        return false; 
    } 
}