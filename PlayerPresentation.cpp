#include "PlayerPresentation.h"

PlayerPresentation::PlayerPresentation()
{
    if(!_playerSpaceshipTexture.loadFromFile("player.PNG")) {
        std::cerr << "Error Loading Player Texture";
    }
    _playerSpaceshipTexture.setSmooth(true);
    _Player.setTexture(_playerSpaceshipTexture);
    _Player.setScale(sf::Vector2f(0.1, 0.1));
    _Player.setPosition(PlayerXPosition, PlayerYPosition);


}

sf::Sprite PlayerPresentation::getPlayer()
{
    return _Player;
}

void PlayerPresentation::draw(sf::RenderWindow& window)
{

    window.draw(_Player);
    
}

void PlayerPresentation::rotateSprite(float angle)
{
    _Player.rotate(angle);
}

void PlayerPresentation::restartPlayerPresentation()
{
    float rotation = _Player.getRotation();
    _Player.rotate(-rotation);
}

void PlayerPresentation::setPositionofPlayer(float xPosition, float yPosition){
    _Player.setPosition(xPosition, yPosition);
}