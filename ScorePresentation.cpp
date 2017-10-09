#include "ScorePresentation.h"

ScorePresentation::ScorePresentation():_scoreMessege{"Highest Score: "}{
    
}
void ScorePresentation::setUpText(int highestScore){
    if (!_scoreFont.loadFromFile("arial.ttf")){
        std::cerr << "Could not load font for score presentation";
    }
    _scoreText.setFont(_scoreFont);
}
