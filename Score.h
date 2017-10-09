#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "GameCommonData.h"
#include "ScoreDatabase.h"

class Score{
public:
    Score();
    Score(std::string name);
    
    ///PLAYER SCORE MANAGEMENT
    void increasePoints(int scoreIncrement);
    void storeScore();
    
    // GETTERS
    int getScore()const;
    int getHighestScore()const;
    std::vector<PlayerDetails> getTop10Scores()const;
    std::vector<int> getTop10ScoresInt()const;
    void insertScore();
private:
// score tracking variables
    int _currentScore;
    int _highestScore;
    
    // Database comunication related
    ScoreDatabase _Database;
    void loadingScores(); // a client does not need to load scores this should be automatic
    
    PlayerDetails _playerDetails;
    // To return Player Structures
    std::vector<PlayerDetails> _playerDetailsVect;
    std::vector<int> _scoresVect;
    
// sorting and insertion of scores

    
};

#endif