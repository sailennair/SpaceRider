#ifndef GAMECOMMONDATA_H_INCLUDED
#define GAMECOMMONDATA_H_INCLUDED
#include <string>
#include <iostream>

const int GameXWindow = 800;
const int GameYWindow = 600;

const int CenterXGameWindow = GameXWindow / 2;
const int CenterYGameWindow = GameYWindow / 2;

const int radius = (GameYWindow - 70) / 2 - 20;
const int centerPlayerRadius = (GameYWindow - 30) / 2 - 10;

const int NumberOfEnemies = 5;

// Size of Player
const int PlayerWidth = 47;
const int PlayerHeight = 70;

const int PlayerXPosition = (CenterXGameWindow)-20;
const int PlayerYPosition = GameYWindow - 70;

const int PlayerHealth = 100;

const int xOrigin = PlayerXPosition;
const int yOrigin = (GameYWindow / 2);

enum class Direction { LEFT, RIGHT };

/**This struct holds the players details to compare to other players highest score.
 * This feature is not yet functional and therefore is not used in the game.
 * @class PlayerDetails
 * @author William and Sailen
 * @date 17/10/2017
 * @file GameCommonData.h
 * @brief This struct holds the players details to compare to other players highest score
 * @var name string contaning the player's name.
 * @var score integer containing the player's score.
 */
struct PlayerDetails {
    std::string name;
    int score;
};

#endif // GAMECOMMONDATA_H
