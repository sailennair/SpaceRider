#include "LaserGeneratorPresentation.h"

LaserGeneratorPresentation::LaserGeneratorPresentation()
{
    
    for(auto i = 0; i < 2 ; i++){
        EnemyPresentation laserGeneratorPresentation(1);
        laserGeneratorPresentationVector.push_back(laserGeneratorPresentation);
    }
    
    for(auto i = 0; i< 20; i++){
        EnemyBulletPresentation laserBulletPresentation;
        laserBulletPresentationVector.push_back(laserBulletPresentation);
    }
    
}


void LaserGeneratorPresentation::draw(RenderWindow &window){
    
    
     for(auto& iter :laserBulletPresentationVector){
       iter.draw(window);
   }
   for(auto& iter :laserGeneratorPresentationVector ){
       iter.draw(window);
   }
   
  
}


