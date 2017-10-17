#include "FireAnimation.h"

FireAnimation::FireAnimation()
{
}

FireAnimation::FireAnimation(float x, float y)
{
    _explosion.setPosition(x, y);
    _explosion.setScale(sf::Vector2f(1.25, 1.25));
}

void FireAnimation::draw(sf::RenderWindow& window)
{
      if(_spriteSheetcount >3) {
        _spriteSheetcount = 0;
        _yspriteSheetCount++;
    }

    if(!_explosionTexture.loadFromFile("explosion.png")) {
        std::cerr << "Error Loading Player Texture";
    }

    _explosion.setTexture(_explosionTexture);
    _explosion.setTextureRect(sf::IntRect(64 * _spriteSheetcount, 64 * _yspriteSheetCount, 64, 64));
    window.draw(_explosion);
  
_spriteSheetcount++;
    if(_yspriteSheetCount >3) {
        _yspriteSheetCount = 0;
    }

}