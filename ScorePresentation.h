#ifndef SCOREPRESENTATION_H
#define SCOREPRESENTATION_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScoreDatabase.h"

class ScorePresentation{
public:
ScorePresentation();
    ScorePresentation(int highestScore);
    void draw(sf::RenderWindow& window , float x, float y);
    
    // If the highest score changes during the game 
    //then this will change the highestes score message displayeed
    void setScoreMessage(int highestScore);

private:
    sf::Font _scoreFont;
    sf::Text _scoreText;
    std::string _scoreMessage;

};

#endif