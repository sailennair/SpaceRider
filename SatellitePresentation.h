#ifndef SATELLITEPRESENTATION_H 
#define SATELLITEPRESENTATION_H 
 
#include <SFML/Graphics.hpp> 
#include <iostream> 
 
class SatellitePresentation{ 
public: 
    SatellitePresentation(); 
     
    void draw(sf::RenderWindow& window, float x, float y); 
     
private: 
    sf::Sprite _satellite; 
    sf::Texture _satelliteTexture; 
   
}; 
 
 
#endif 