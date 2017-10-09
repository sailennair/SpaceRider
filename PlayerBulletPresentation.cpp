#include "PlayerBulletPresentation.h"

PlayerBulletPresentation::PlayerBulletPresentation(int xpos, int ypos, int type)
{
    if(type == 1){
    _rect.setRadius(3);
    _rect.setFillColor(Color::Green);
    }
    
    if(type == 2){
    _rect.setRadius(6);
    _rect.setFillColor(Color::Red);
    }
    
    
    _rect.setPosition(xpos,ypos);
    
}

CircleShape PlayerBulletPresentation::getBullet(){
    return _rect;
}

void PlayerBulletPresentation:: draw(RenderWindow &window){
    window.draw(_rect);
}

void PlayerBulletPresentation::updateBullet(int xpos, int ypos){
    _rect.setPosition(xpos,ypos);
    
}


