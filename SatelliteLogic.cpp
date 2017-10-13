#include "SatelliteLogic.h"

SatelliteLogic::SatelliteLogic(float x, float y, float theta)
    : _xPos{ x }
    , _yPos{ y }
    , _spawnedXpos{ x }
    , _spawnedYpos{ y }
    , _angleOfRotation{ theta }
    , _health{ 20 }
    , _radius{ 15 }
    , _radiusOfRotation{ 10 }
{
    _centerXPosition = x + _radiusOfRotation * cos(_angleOfRotation);
    _centerYPosition = y + _radiusOfRotation * sin(_angleOfRotation);
}

void SatelliteLogic::move()
{
    // chosing a new point to rotate about
    auto xPoint = _spawnedXpos + _radiusOfRotation;
    auto yPoint = _spawnedYpos + _radiusOfRotation;

    float s = sin(_angleOfRotation);
    float c = cos(_angleOfRotation);

    //    // translating the position to a rotation origen
    auto translatedX = _xPos - xPoint;
    auto translatedY = _yPos - yPoint;

    //    //rotation about origin
    auto newXpos = translatedX * c - translatedY * s;
    auto newYpos = translatedX * s + translatedY * c;

    _centerXPosition = _xPos + 15 * cos(_angleOfRotation);
    _centerYPosition = _yPos + 50 * sin(_angleOfRotation);
    //    // translate the point back to a rotation about xPoint YPoint
    _xPos = newXpos + xPoint;
    _yPos = newYpos + yPoint;
}

// Getter functions

float SatelliteLogic::getXposition()
{
    return _xPos; // - radius * cos(_angleOfRotation);
}
float SatelliteLogic::getYposition()
{
    return _yPos; // - radius * sin(_angleOfRotation);
}

bool SatelliteLogic::isAlive()
{
    if(_health > 0) {
        return true;
    } else {
        return false;
    }
}

void SatelliteLogic::decreaseHealth(int damage)
{
    _health -= damage;
}

float SatelliteLogic::getRadius()
{
    return _radius;
}

float SatelliteLogic::getCenterXPosition()
{
    return _centerXPosition;
}

float SatelliteLogic::getCenterYPosition()
{
    return _centerYPosition;
}
