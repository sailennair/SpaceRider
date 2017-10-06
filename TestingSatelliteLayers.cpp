#include <SFML/Graphics.hpp>
#include "SatelliteLogic.h"
#include "SatellitePresentation.h"

using namespace sf;
using namespace std;

int main(){
    RenderWindow window(VideoMode(800, 600), "Enemy");
    window.setMouseCursorVisible(false);
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    
    SatelliteLogic satLogic(400, 300, 0.175); // 0.175 = SPEED OF ROTATION
    SatellitePresentation satPresent;
    
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            

            
         
        }   
        
        window.clear(Color::Black);      //This sets the window black
        satLogic.move();
        satPresent.draw(window, satLogic.getXposition(), satLogic.getYposition());
        window.display();               //This applies the changes to the window
        
     }
     return 0;
}