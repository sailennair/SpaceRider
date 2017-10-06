#ifndef COLLISION_H
#define COLLISION_H

#include "IMovingGameObject.h"

class Collision{
public:
    bool didObjectsCollide( IMovingGameObject& obj1,  IMovingGameObject& obj2);
};


#endif