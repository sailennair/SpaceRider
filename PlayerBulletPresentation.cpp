#include "PlayerBulletPresentation.h"

PlayerBulletPresentation::PlayerBulletPresentation(int xpos, int ypos, int type)
{
    if(type == 1){
    _bullet.setRadius(3);
    _bullet.setFillColor(Color::Green);
    }
    
    if(type == 2){
    _bullet.setRadius(6);
    _bullet.setFillColor(Color::Red);
    }
    
    _bullet.setPosition(xpos,ypos);
    
}

CircleShape PlayerBulletPresentation::getBullet(){
    return _bullet;
}

void PlayerBulletPresentation:: draw(RenderWindow &window){
    window.draw(_bullet);
}

void PlayerBulletPresentation::updateBullet(int xpos, int ypos){
    _bullet.setPosition(xpos,ypos);
}


