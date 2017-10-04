#ifndef GAMECOMMONDATA_H_INCLUDED
#define GAMECOMMONDATA_H_INCLUDED

const int GameXWindow = 800;
const int GameYWindow = 600;

const int CenterXGameWindow = GameXWindow/2;
const int CenterYGameWindow = GameYWindow/2;

const int radius = (GameYWindow - 70) / 2 - 20;

const int NumberOfEnemies = 10;

// Size of Player
const int PlayerWidth = 47;
const int PlayerHeight = 70;

const int PlayerXPosition = (GameXWindow / 2) - 20;
const int PlayerYPosition = GameYWindow - 70;

const int PlayerHealth = 100;

const int xOrigin = PlayerXPosition;
const int yOrigin = (GameYWindow / 2);

enum class Direction { LEFT, RIGHT };

// TEsting  the git communication
#endif // GAMECOMMONDATA_H
