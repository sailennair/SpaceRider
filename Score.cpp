#include "Score.h"
#include <iostream>

Score::Score():
    _playerName{"William"},
    _currentScore{0},
    _currentPlayerHighestScore{0}
{
     ScoreDatabase _Database();
}

Score::Score(std::string name, std::string filename):
    _playerName{name},
    _currentScore{0},
    _currentPlayerHighestScore{0},
    _highestScore{0},
    _Database(filename)
{
     //ScoreDatabase ;
     _highestScoreFromDataBase = _Database.readScoreFromFile();
     std::cout << "Highest score Score Constructor" << " " << _highestScoreFromDataBase  << std::endl;
}

void Score::setScorePoints(int scoreIncrement){
    _currentScore += scoreIncrement;
    _highestScoreFromDataBase = _Database.readScoreFromFile(); 
    if (_currentScore > _currentPlayerHighestScore){
        _currentPlayerHighestScore = _currentScore;
        std::cout << " 10 Points" << std::endl;
    }
    
    // need to update the database
    if (_currentPlayerHighestScore > _highestScoreFromDataBase){
        _highestScoreFromDataBase = _currentPlayerHighestScore;
        std::cout << " Wrtiting to File From within Score" << std::endl ;
        _Database.writeScoreToFile(_playerName, _highestScoreFromDataBase);
    }      
    
}

int Score::getScore()const{
    return _currentScore;
}

int Score::getCurrentPlayerHighestScore(){
    return _currentPlayerHighestScore;
}

int Score::getHighestScore(){
    return _highestScore;
}
