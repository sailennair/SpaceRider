#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H

#include <math.h>

class EnemyLogic{
public:
    EnemyLogic(int x, int y, int width, int height ,float theta);
    // The move function changes the position invariants of the enemy which can be accessed using the getters
    void move();
    
    //Getters Of Enemy Invariants
    int getXPosition();
    int getYPosition();    
    int getCenterX();
    int getCenterY();
    int getTheta();    
    int getHealth();
   
    // This function decreases the health invariant by the damage.
    void decreaseHealth(int damage);
    
    // Returns true if health > 0
    bool isAlive();
    
    // To scale the Enemy dimensions by the change
    void reSize(int changeInWidth, int changeInHeight);
private:
    // Position and Dimensions of enemy;
    int _xPos;
    int _yPos;
    int _width;
    int _height;
    float _theta;
        
    // The size scale of the enemy.
    int _scale;
    
    //Health of enemy
    int _health;
    
};
#endif