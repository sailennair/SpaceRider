#include <SFML/Graphics.hpp>
#include "ScorePresentation.h"
#include "Score.h"

using namespace sf;

int main(){
//    RenderWindow window(VideoMode(800, 600), "Score");
//    window.setMouseCursorVisible(false);
//    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
//    window.setVerticalSyncEnabled(true);
    Score score;
    // Increasing the scores BY 45
    score.increasePoints(45);

// INSERT SCORE MUST BE CALLED WHEN EITHER THE PLAYER DIES OR WINS AND IT MUST BE FOLLOWED BY STORESCORE ALLWAYS
    score.insertScore();    
    score.storeScore();
    
//    while(window.isOpen()){
//
//        
//        
//        Event event;
//        while(window.pollEvent(event)){
//           
//            if(event.type ==  Event::Closed){
//                window.close();
//                break;
//            }
//            
//            
//            
//         
//        }   
//        
//        window.clear(Color::Black);      //This sets the window black
//       
//        window.display();               //This applies the changes to the window
//        
//     }
    
    return 0;
}