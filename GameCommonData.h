#ifndef GAMECOMMONDATA_H_INCLUDED
#define GAMECOMMONDATA_H_INCLUDED

const int GameXWindow = 700;
const int GameYWindow = 1000;

const int radius = GameYWindow - 70;

const int NumberOfEnemies = 10;

//Size of Player
const int PlayerWidth = 47;
const int PlayerHeight = 70;

const int PlayerXPosition = (GameXWindow/2) - 20;
const int PlayerYPosition = GameYWindow - 70;

const int PlayerHealth = 100;

enum class Direction
{
    LEFT,
    RIGHT
};

//TEsting  the git communication
#endif // GAMECOMMONDATA_H
