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
/**
 * @brief Default constructor Inititalise the bullet texture, default position, type and scale. 
 * @param xpos x co-ordinate of the bullets position
 * @param ypos y co-ordinate of the bullets position
 * @param type type of bullet
 */
    PlayerBulletPresentation(int xpos, int ypos, int type);
    /**
     * @brief Returns the CircleShape bullet with all bullet characteristics
     * @return CircleShape containing the bullet deatils
     */
   
    CircleShape getBullet();
    /**
     * @brief Draws the bullet in the window defined by the parameter window
     * @param window to draw the bullet on.
     */
    void draw(RenderWindow &window);
    /**
     * @brief Updates the bullet CircleShape position as the bullet moves
     * @param xpos x co-ordinate the bullet moved to
     * @param ypos y co-ordinate the bullet moved to
     */
    void updateBullet(int xpos, int ypos);

private:
  CircleShape _bullet;
    


};

#endif // PLAYERBULLETPRESENTATION_H
