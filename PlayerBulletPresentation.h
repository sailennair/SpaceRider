#ifndef PLAYERBULLETPRESENTATION_H
#define PLAYERBULLETPRESENTATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameCommonData.h"
#include <memory>




using namespace sf;
using namespace std;

class PlayerBulletPresentation
{
public:

    PlayerBulletPresentation(int xpos, int ypos, int type);
    
    CircleShape getBullet();
    
    void draw(RenderWindow &window);
    
    void updateBullet(int xpos, int ypos);
    
    
    
    
  
private:
  CircleShape _bullet;
    


};

#endif // PLAYERBULLETPRESENTATION_H
