#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <fstream>
#include "ScoreDatabase.h"

class Score{
public:
    Score();
    Score(std::string name, std::string filename);
    void setScorePoints(int scoreIncrement);
    
    // GETTERS
    int getScore()const;
    int getCurrentPlayerHighestScore();// Static function top be able to access a static variable
    int getHighestScore();
private:
    std::string _playerName;    
    int _currentScore;
    int _currentPlayerHighestScore;
    int _highestScore;
    int _highestScoreFromDataBase;
    
    ScoreDatabase _Database;
};

#endif