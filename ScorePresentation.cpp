#include "ScorePresentation.h"

ScorePresentation::ScorePresentation(int highestScore):_scoreMessage{"Highest Score: "}{
    if (!_scoreFont.loadFromFile("arial.ttf")){
        std::cerr << "Could not load font for score presentation";
    }
    _scoreText.setFont(_scoreFont);
    _scoreMessage = _scoreMessage + std::to_string(highestScore);
    _scoreText.setString(std::string(_scoreMessage));
    _scoreText.setCharacterSize(30);
    _scoreText.setColor(sf::Color::Blue);
    _scoreText.setPosition(sf::Vector2f(300, 300));
}
//void ScorePresentation::setUpText(){
//    if (!_scoreFont.loadFromFile("arial.ttf")){
//        std::cerr << "Could not load font for score presentation";
//    }
//    _scoreText.setFont(_scoreFont);
//    
//    
//}

//void ScorePresentation::setScoreMessage(int highestScore){
//    _scoreMessage = _scoreMessage + std::to_string(highestScore);
//    _scoreText.setString(_scoreMessage);
//}

void ScorePresentation::draw(sf::RenderWindow& window , float x, float y){
    std::cout << _scoreMessage << std::endl;
    _scoreText.setPosition(sf::Vector2f(x, y));
    window.draw(_scoreText);
    std::cout << " I am Drawing" << std::endl;
}