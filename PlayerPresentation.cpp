#include "PlayerPresentation.h"

PlayerPresentation::PlayerPresentation()
{
     if(!_playerSpaceshipTexture.loadFromFile("player.PNG")) {
        std::cerr << "Error Loading Player Texture";
    }
    _playerSpaceshipTexture.setSmooth(true);
    _Player.setTexture(_playerSpaceshipTexture);
    _Player.setScale(Vector2f(0.1, 0.1));
    //_Player.setPosition(200,200);
    
    _rect.setSize(Vector2f(20,20));
    _rect.setFillColor(sf::Color::Blue);
    _rect.setPosition(200,200);
}

Sprite PlayerPresentation::getPlayer(){
    return _Player;
}

void PlayerPresentation::draw(RenderWindow &window){
    //std::cout<<"yes"<<std::endl;
    window.draw(_Player);
   // window.draw(_rect);
}