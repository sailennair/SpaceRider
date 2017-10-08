#include "PlayerPresentation.h"

PlayerPresentation::PlayerPresentation()
{
     if(!_playerSpaceshipTexture.loadFromFile("player.PNG")) {
        std::cerr << "Error Loading Player Texture";
    }
    _playerSpaceshipTexture.setSmooth(true);
    _Player.setTexture(_playerSpaceshipTexture);
    _Player.setScale(Vector2f(0.1, 0.1));
    _Player.setPosition(PlayerXPosition,PlayerYPosition);
    
  //  _rect.setSize(Vector2f(40,70));
  _rect.setRadius(1);
    _rect.setFillColor(sf::Color::Blue);
  
}

Sprite PlayerPresentation::getPlayer(){
    return _Player;
}

void PlayerPresentation::draw(RenderWindow &window){
   
    window.draw(_Player);
     window.draw(_rect);
}

void PlayerPresentation::rotateSprite(float angle){
    _Player.rotate(angle);
    _rect.rotate(angle);
}