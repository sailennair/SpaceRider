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

    PlayerBulletPresentation(int xpos, int ypos);
    
    RectangleShape getBullet();
    
    void draw(RenderWindow &window);
    
    
    
private:
    RectangleShape _rect;

};

#endif // PLAYERBULLETPRESENTATION_H
