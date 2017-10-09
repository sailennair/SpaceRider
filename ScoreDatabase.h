#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <fstream>
#include <windows.h>
#include <iostream>

class ScoreDatabase{
public:
    ScoreDatabase();
    ScoreDatabase(std::string fileName);
    // This function returns the highest score in Database
    int readScoreFromFile();
    // writes the highest score to database and the name of the persong who got that score
    void writeScoreToFile(int score);
    void setScorePoints(int scoreIncrement, const std::string& name);
    
private:
// fstream variables
    std::string _fileName;
    std::ifstream _ReadFile;
    std::ofstream _WriteFile;
// score variables
    std::string _PlayerName;
    int _highestScore;
    int _currentScore;
    int _currentPlayerHighestScore;
    int _tempScore;
//    int _highestScoreLineNumber;
};

#endif