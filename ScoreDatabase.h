#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <iostream>
#include "GameCommonData.h"
//! Responsible for reading and writting to the database.
/*! This class is responsible for reading and writting to the database .
\author Sailen Nair and William Becerra
 *
*/
class ScoreDatabase{
public:
/** Default Constructor checks if there is an excisting database if there isnt one it intitializes a database.
 *  The database is stored in a file called score.dat with hidden and read only file attributes
 */
    ScoreDatabase();
   
/** Reads from data base.
 * @return vector of intergers with all the entries in the database.
 * @see writeScoreToFile
 */
    std::vector<int> readScoreFromFileInt();

/** Reads from data base.
 *  This functionality is not fully implemented and its not used in the game.
 * @return vector of PlayerDetails with all the entries in the database.
 * @see readScoreFromFileInt()
 */
    std::vector<PlayerDetails> readScoreFromFile();

/** Writes the information in the parameter to the database
 * @param vector of integers containing scores
 * @see readScoreFromFileInt
 */  
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
    void toggleFilePermission();
};

#endif