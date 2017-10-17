#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "GameCommonData.h"
#include "ScoreDatabase.h"

//! Contols the logic of the score System.
/*! This class is responsible for controlling the score system.
\author Sailen Nair and William Becerra
 *
*/

class Score
{
public:
    /** Default constructor.
     *  Initilises a Database instance, gets highest score from database and sets the current score to zero.
     */
    Score();
    /** Score class constructor for a player with a name given by the parameter.
     *  Does the same initilization as default constuctor and it also intilises a PlayerDetails object of name given by
     * the parameter.
     *  @param name string containing the players name
     */
    Score(std::string name);

    /** Increases the players score by an amount given by the parameter.
     * @param scoreIncrement integer containing the increase in score.
     */
    void increasePoints(int scoreIncrement);
    /** Stores the current score in data base.
     *  This function makes a call to the ScoreDatabase function writeScoreToFile.
     */
    void storeScore();

    /** Getter function to access the current score of the player.
     * @return interger containing the current player.
     */
    int getScore();

    /** Getter function to access the Highest Score in the game.
     * This function is able to return the highest score live, as the player beats the highest score in game.
     * @return interger containing the Highest Scorer.
     * @see getScore().
     */
    int getHighestScore();

    /** Getter function to access the top 10 highest scores in the game.
     *  This function is not a feature used yet in the game.
     * @return vector of PlayerDetails containing the top 10 players with highest scores.
     * @see getTop10ScoresInt().
     */
    std::vector<PlayerDetails> getTop10Scores();
    /** Getter function to access the top 10 highest scores in the game.
    * @return vector of integers containing the top 10 highest scores.
    */
    std::vector<int> getTop10ScoresInt();

    /** Function performs the sorting algorithm to insert the score in the correct position in the data base.
     * This function keeps the _scoresVect with a maximum of 10 score elements. Ordered from highest to smallest.
     */
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