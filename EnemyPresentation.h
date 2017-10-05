#ifndef ENEMYPRESENTATION_H
#define ENEMYPRESENTATION_H

#include <SFML/Graphics.hpp>
#include <iostream> // This was included to use cerr.
class EnemyPresentation{
public:
    EnemyPresentation(int windowWidth, int windowHeight, float width, float height);
    
    // This function draws the enemy in the window at positon (xPos, yPos)
    void draw(sf::RenderWindow& window, int xPos, int yPos, float scale, float width, float height);
    
    // Returns true if the enemy is outside the screen
    bool isOutOfScreen(const int windowWidth, const int windowHeight, const int xPos, const int yPos)const;
    
private:
    sf::Sprite _enemy;
    sf::Texture _enemyTexture;
    sf::Vector2i _centerOfWindow;
    sf::Vector2f _scale;
    sf::RectangleShape _rectange;
 };

#endif