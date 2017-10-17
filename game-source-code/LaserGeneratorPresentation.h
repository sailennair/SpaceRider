#ifndef LASERGENERATORPRESENTATION_H
#define LASERGENERATORPRESENTATION_H

#include <SFML/Graphics.hpp>
#include "GameCommonData.h"

#include "EnemyBulletPresentation.h"
#include "EnemyPresentation.h"

//! Controls the presentation of laser generators.
/*! This class is responsible for controlling the laser generators graphical representation.
\author Sailen Nair and William Becerra
 *
*/
class LaserGeneratorPresentation
{
public:
    /** Default constructor inititalise the laser generators aircraft texture, default position, type and scale.
     * The laser bean and the laser generator aircrafts graphics are initialised
     */
    LaserGeneratorPresentation();
    /** Draws the Laser generators in the screen defined by the parameter window.
     * @param window to draw the laer on.
     */
    void draw(sf::RenderWindow& window);
    /** Getter function to access the laser generator aircraft graphical representation.
     * @return EnemyPresentation vector containing the laser genrators aircracft graphical representation.
     */
    vector<EnemyPresentation> getLaserGeneratorPresentationVector();

    /** Updates the position of a laser generator aircraft.
     * Void function to update the position of a laser generator number index in the vector of laser generators.
     * @param index integer containing the laser generator aircraft that should be updated.
     * @param xPosition float containing the x co-ordinate to update the laser generator's position to.
     * @param yPosition float containing the y co-ordinate to update the laser generator's position to
     */
    void updateLaserGeneratorEnemy(int index, float xPosition, float yPosition);
    /** Getter function to access the laser's graphical representation.
     *  The laser is created by creating multiple bullites between the laser generator's aircrafts.
     * @return EnemyBulletPresentation vector containing all the bullets creating the laser beam.
     */
    vector<EnemyBulletPresentation> getLaserBulletPresentationVector();

    /** Updates the position of the laser beams.
     * Void function to update the position of the bullet forming the laser beam in the vector of laser bullets.
     * @param index integer containing the laser beam's bullet that should be updated.
     * @param xPosition float containing the x co-ordinate to update the laser beams's bullet position to.
     * @param yPosition float containing the y co-ordinate to update the laser beams's bullet position to
     */
    void updateLaserBulletPresentation(int index, float xPosition, float yPosition);

private:
    vector<EnemyPresentation> laserGeneratorPresentationVector;
    vector<EnemyBulletPresentation> laserBulletPresentationVector;
};

#endif // LASERGENERATORPRESENTATION_H
