#include "Collision.h"

bool Collision::didObjectsCollide( IMovingGameObject& obj1,  IMovingGameObject& obj2){
    
    if((obj1.getXposition() + obj1.getWidth() >= obj2.getXposition()) && (obj1.getYposition() + obj1.getHeight() <= obj2.getYposition())){
        return true;
    }
    return false;
}