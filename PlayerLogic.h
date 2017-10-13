#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include <iostream>
#include <math.h>
#include "IPlayer.h"
#include <memory>

class PlayerLogic : public IPlayer
{
public:
    /**
    * Default constructor Initialises the players position and the radius from the center of the screen.
    */
    PlayerLogic();
    /**
     * @brief Moves Player x co-oridnate in a circular motion to the left. The circular movement keeps the same distance
     * from the center of the screen.
     */
    void moveLeftX();
    /**
     * @brief Moves Player y co-oridnate in a circular motion to the left. The circular movement keeps the same distance
     * from the center of the screen.
     */
    void moveLeftY();
    /**
     * @brief Moves Player x co-oridnate in a circular motion to the right. The circular movement keeps the same
     * distance from the center of the screen.
     */
    void moveRightX();
    /**
     * @brief Moves Player y co-oridnate in a circular motion to the right. The circular movement keeps the same
     * distance from the center of the screen.
     */
    void moveRightY();
    /**
     *  @brief Returns the angel of reotation of the player. The angle of rotation represents angular the step sizes at
     * which the player rotates
     */
    float getAngleofRotation();
    /**
     * @brief Returns true if the player is health is greater than zero.
     * @return boolean true if player alive.
     */
    bool isAlive();
    /**
     * @brief Subtructs a damge amount from the players health.
     * @param _damage this sets a damage amount to be subtructed from the players health.
     */
    void reduceHealth(int _damage);
    /**
     * @brief Returns x co-ordinate of the player's current position.
     * @return float containing players x co-ordinate position.
     */
    float getXposition();
    /**
     * @brief Returns y co-ordinate of the player's current position.
     * @return float containing players y co-ordinate position.
     */
    float getYposition();
    /**
     * @brief Returns the angle of the player's current position from the players starting position.
     * @return float containing players current angle.
     */
    float getTheta();
    /**
     * @brief Used to convert degrees to radians.
     * @param angle in radians.
     * @return float angle in degrees.
     */
    float degreesToRadians(float x);
    /**
     * @brief Moves the player left or right for depending on user input.
     * @param Direction strongly typed enum class.
     */
    void playerMove(Direction dir);
    /**
     * @brief Returns the radius of the player.
     * @return float containing players radius.
     */
    float getRadius();
    /**
     * @brief Returns the center x co-ordinate of the player's current position.
     * @return float containing players x co-ordinate of the center.
     */
    float getCenterXPosition();
    /**
     * @brief Returns the center y co-ordinate of the player's current position.
     * @return float containing players y co-ordinate of the center.
     */
    float getCenterYPosition();
    /**
     * @brief Returns the players health.
     * @return int containing player's health.
     */
    int getHealth();
    /**
     * @brief Sets the players alive status to dead or alive.
     * @param boolean life status. false to set player to dead.
     */
    void setLife(bool life);
    /**
     * @brief Resets the player to its starting positon
    */
    void playerRestart();

private:
    bool _life = true;
    int _health;
    float _theta = (PI) / 2;
    int _xpos;
    int _ypos;
    float _angleOfRotation;
    float _radius;
    float _centerXPosition;
    float _centerYPosition;
};

#endif // PLAYERLOGIC_H