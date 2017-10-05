#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H

#include <math.h>

class EnemyLogic{
public:
    EnemyLogic(float x, float y, int width, int height ,float theta);
    // The move function changes the position invariants of the enemy which can be accessed using the getters
    void move();
    
    //Getters Of Enemy Invariants
    float getXPosition();
    float getYPosition();    
    int getCenterX();
    int getCenterY();
    int getTheta();    
    int getHealth();
    float getScale();
   
   void moveToCenter(float x, float y, float theta);
    // This function decreases the health invariant by the damage.
    void decreaseHealth(int damage);
    
    // Returns true if health > 0
    bool isAlive();
    
    // To scale the Enemy dimensions by the change
    void reSize(int changeInWidth, int changeInHeight);
private:
    // Position and Dimensions of enemy;
    float _xPos;
    float _yPos;
    float _width;
    float _height;
    float _originalWidth;
    float _originalHeight;
    float _theta;
        
    // The size scale of the enemy.
    float _scale;
    float _originalScale;
    
    //Health of enemy
    int _health;
    
    
    int deltaX;
    int deltaY;
    
};
#endif