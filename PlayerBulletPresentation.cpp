#include "PlayerBulletPresentation.h"

PlayerBulletPresentation::PlayerBulletPresentation(int xpos, int ypos)
{
    _rect.setSize(Vector2f(5,5));
    _rect.setFillColor(Color::Red);
    _rect.setPosition(xpos,ypos);
    
}

RectangleShape PlayerBulletPresentation::getBullet(){
    return _rect;
}

void PlayerBulletPresentation:: draw(RenderWindow &window){
    window.draw(_rect);
}

void PlayerBulletPresentation::updateBullet(int xpos, int ypos){
    _rect.setPosition(xpos,ypos);
    
}


