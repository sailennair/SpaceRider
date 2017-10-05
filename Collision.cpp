#include "Collision.h"

Collision::didObjectsCollide(const IMovingGameObject& obj1, const IMovingGameObject& obj2){
    
    if((obj1.getXPosition() + getWidth() >= obj2.getXposition()) && (obj1.getYPosition + obj1.getYHeight()) <= obj2.getYPosition()){
        return true;
    }
    return false;
}