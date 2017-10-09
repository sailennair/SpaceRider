#include <SFML/Graphics.hpp>
#include "ScorePresentation.h"
using namespace sf;
int main(){
    RenderWindow window(VideoMode(800, 600), "Score");
    window.setMouseCursorVisible(false);
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    ScorePresentation Score(100);
    while(window.isOpen()){

        
        
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            
            
         
        }   
        
        window.clear(Color::Black);      //This sets the window black
        Score.draw(window, 300, 300);
        window.display();               //This applies the changes to the window
        
     }
    
    return 0;
}