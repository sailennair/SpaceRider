#include "Score.h"

Score::Score()
    : _currentScore{ 0 },
    _highestScore{0}
{
    ScoreDatabase _Database();
    loadingScores();
}

Score::Score(std::string name)
    : _currentScore{ 0 }
{
    ScoreDatabase _Database();
    _playerDetails.name = name;
    _playerDetails.score = _currentScore;
    loadingScores();
}

/// PLAYER SCORE MANAGEMENT
void Score::increasePoints(int scoreIncrement)
{
    _currentScore += scoreIncrement;
    if(_currentScore > _highestScore)
        _highestScore = _currentScore;
}

void Score::insertScore()
{
    std::sort(begin(_scoresVect), end(_scoresVect)); // sorted in ascending order
    std::reverse(
        begin(_scoresVect), end(_scoresVect)); // reverse the order so that the lowest score is always at the back

    if(_scoresVect.size() < 10) {
        _scoresVect.push_back(_currentScore);
        std::sort(begin(_scoresVect), end(_scoresVect));
        std::reverse(begin(_scoresVect), end(_scoresVect));
        _highestScore = _scoresVect[0];
    } else {
        _scoresVect.push_back(_currentScore);
        std::sort(begin(_scoresVect), end(_scoresVect));
        std::reverse(begin(_scoresVect), end(_scoresVect));
        _highestScore = _scoresVect[0];
        _scoresVect.pop_back();
    }
}

///  GETTERS
int Score::getScore()
{
    return _currentScore;
}

int Score::getHighestScore()
{
    return _highestScore;
}

std::vector<PlayerDetails> Score::getTop10Scores()
{
    return _playerDetailsVect;
}

std::vector<int> Score::getTop10ScoresInt()
{
    return _scoresVect;
}

// DATABASE COMMUNICATION FUNCTIONS
void Score::loadingScores()
{

    _scoresVect = _Database.readScoreFromFileInt();
    if(_scoresVect.size() > 0) {
        _highestScore = _scoresVect[0];
    }
}
/// This Will be for a Player Details Reading
// void Score::loadingScores(){
//    _playerDetailsVect = _Database.readScoreFromFile();
//}

void Score::storeScore()
{
    insertScore();
    _Database.writeScoreToFile(_scoresVect);
}
/// This will be to write a Player Details vector
// void Score::storeScore(){
//    _Database.writeScoreToFile(_playerDetailsVect);
//}
