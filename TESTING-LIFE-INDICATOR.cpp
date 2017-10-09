#include <SFML/Graphics.hpp>
#include "LifePresentation.h"
#include "LifeLogic.h"
#include <iostream>
using namespace std;
using namespace sf;

int main(){
    RenderWindow window(VideoMode(800, 600), "Enemy");
    window.setMouseCursorVisible(false);
//This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    LifePresentation Life;
    
    // Creating a Logic object at positions (20, 570)
    LifeLogic lifelogic(20, 570);
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            
            
         
        }
        //when Player gets hit this should be call
        int lives = lifelogic.getNumberOfLivesRemaining(10);
        
        window.clear(Color::Black);
        // Setting the number of lives
        Life.setLifeCount(lives);
        // getting the position to draw from logic
        Life.draw(window, lifelogic.getXpos(), lifelogic.getYpos());
        window.display();
    
   
    }
     return 0;
}
