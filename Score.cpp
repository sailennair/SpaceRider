#include "Score.h"

Score::Score():
    _currentScore{0}
{
     ScoreDatabase _Database();
     loadingScores();
}

Score::Score(std::string name):
    _currentScore{0}
{
    ScoreDatabase _Database();
    _playerDetails.name = name;
    _playerDetails.score = _currentScore;
    loadingScores();
}

/// PLAYER SCORE MANAGEMENT
void Score::increasePoints(int scoreIncrement){
    _currentScore += scoreIncrement;     
}

void Score::insertScore(){
    std::sort(begin(_scoresVect), end(_scoresVect));  //sorted in ascending order
    std::reverse(begin(_scoresVect), end(_scoresVect)); // reverse the order so that the lowest score is always at the back
    
    if(_scoresVect.size() < 10){
        _scoresVect.push_back(_currentScore);
        std::sort(begin(_scoresVect), end(_scoresVect));
        std::reverse(begin(_scoresVect), end(_scoresVect));
    }else{
        _scoresVect.push_back(_currentScore);
        std::sort(begin(_scoresVect), end(_scoresVect));
        std::reverse(begin(_scoresVect), end(_scoresVect));
        _scoresVect.pop_back(); 
    }
}


///  GETTERS
int Score::getScore()const{
    return _currentScore;
}

int Score::getHighestScore()const{
    return _highestScore;
}

std::vector<PlayerDetails> Score::getTop10Scores()const{
    return _playerDetailsVect;
}

std::vector<int> Score::getTop10ScoresInt()const{
    return _scoresVect;
}


// DATABASE COMMUNICATION FUNCTIONS
void Score::loadingScores(){
    _scoresVect = _Database.readScoreFromFileInt();
}
/// This Will be for a Player Details Reading
//void Score::loadingScores(){
//    _playerDetailsVect = _Database.readScoreFromFile();
//}

void Score::storeScore(){
    _Database.writeScoreToFile(_scoresVect);   
}
/// This will be to write a Player Details vector
//void Score::storeScore(){
//    _Database.writeScoreToFile(_playerDetailsVect);
//}



//else{
//        auto it = begin(_scoresVect);
//        for(unsigned int i = 0; i < _scoresVect.size(); i++){
//            it++;
//            if((i == 0 &&  _scoresVect[i] < _currentScore)){
//                _scoresVect.insert(it, _currentScore);
//                //_scoresVect[i] = _currentScore;
//                //_scoresVect.pop_back();
//            }
//            
//            if((i != 0 && i!=_scoresVect.size()-1) && ((_scoresVect[i] < _currentScore) && _scoresVect[i+1] > _currentScore )){
//                     _scoresVect.insert(it, _currentScore);
//                   // _scoresVect.pop_back();
//            }
