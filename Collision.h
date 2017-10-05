#ifndef COLLISION_H
#define COLLISION_H

//#include "IMovingGameObject.h"

class Collision{
public:
    bool didObjectsCollide(const IMovingGameObject& obj1, const IMovingGameObject& obj2);
};


#endif