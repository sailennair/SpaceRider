#include "PlayerPresentation.h"

PlayerPresentation::PlayerPresentation()
{
     if(!_playerSpaceshipTexture.loadFromFile("player.PNG")) {
        std::cerr << "Error Loading Player Texture";
    }
    _playerSpaceshipTexture.setSmooth(true);
    _Player.setTexture(_playerSpaceshipTexture);
    _Player.setScale(Vector2f(0.1, 0.1));
}

Sprite PlayerPresentation::getPlayer(){
    return _Player;
}

void PlayerPresentation::draw(RenderWindow &window){
    window.draw(_Player);
}