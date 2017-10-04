#include "EnemyPresentation.h"

EnemyPresentation::EnemyPresentation(int windowWidth, int windowHeight){

    if(!_enemyTexture.loadFromFile("spacestation.png")) {
        std::cerr << "Error Loading Player Texture";
    }
    _enemyTexture.setSmooth(true);
    _enemy.setTexture(_enemyTexture);
    
    _centerOfWindow.x = windowWidth/2;
    _centerOfWindow.y = windowHeight/2;
    
    _enemy.setPosition(_centerOfWindow.x, _centerOfWindow.y);
    _scale.x = 0.3;
    _scale.y = 0.3;
    _enemy.setScale(_scale);
}

void EnemyPresentation::draw(sf::RenderWindow& window, int xPos, int yPos){
    _enemy.setPosition(xPos, yPos);
    window.draw(_enemy);
}

bool EnemyPresentation::isOutOfScreen(const int windowWidth, const int windowHeight, const int xPos, const int yPos) const{
    
    if(xPos > 0 && xPos < windowWidth && yPos > 0 && yPos < windowHeight)
        return false;
        
    return true;    
}