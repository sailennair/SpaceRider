#ifndef LASERGENERATORPRESENTATION_H
#define LASERGENERATORPRESENTATION_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include <memory>
#include "EnemyBulletPresentation.h"
#include "EnemyPresentation.h"

using namespace sf;
using namespace std;


class LaserGeneratorPresentation
{
public:
    LaserGeneratorPresentation();
    
    void draw(RenderWindow &window);
    
    //vector<EnemyBulletPresentation> getLaserBulletPresentationVector();
    
  // void updateLaserBulletPresentation(int index, float xPosition, float yPosition);
    
    //void updateAllEntities();
    
    //void updateSingleEntity(float xPosition, float yPositon);
    //vector<EnemyBulletPresentation> laserBulletPresentationVector;
    vector<EnemyPresentation> laserGeneratorPresentationVector;
    
    vector<EnemyBulletPresentation> laserBulletPresentationVector;
//private:    

};

#endif // LASERGENERATORPRESENTATION_H
