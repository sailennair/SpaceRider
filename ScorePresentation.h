#ifndef SCOREPRESENTATION_H
#define SCOREPRESENTATION_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScoreDatabase.h"

class ScorePresentation{
public:
    ScorePresentation();
    void draw(sf::RenderWindow& window , float x, float y);
private:
    void setUpText();
    void setScoreMessage();
    sf::Font _scoreFont;
    sf::Text _scoreText;
    std::string _scoreMessage;

}

#endif