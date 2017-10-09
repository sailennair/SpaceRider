#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <iostream>
#include "GameCommonData.h"

class ScoreDatabase{
public:
    ScoreDatabase();
   
    // This function returns a vector of integer scores
    std::vector<int> readScoreFromFileInt();
    std::vector<PlayerDetails> readScoreFromFile();
    // writes the highest score to database and the name of the person who got that score
    void writeScoreToFile(const std::vector<int>& scoresVect);
   // void writeScoreToFile(const std::vector<PlayerDetails>& playerScoreVect);

    
private:
// fstream variables
    const std::string _fileName = "score.dat"; // The paths should be constant to avoid possible errors
    std::ifstream _ReadFile;
    std::ofstream _WriteFile;
// Score variables
    std::vector<PlayerDetails> _playerDetailsVect;
    std::vector<int> _scores;
    
};

#endif