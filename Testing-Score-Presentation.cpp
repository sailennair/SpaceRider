#include <SFML/Graphics.hpp>
#include "ScorePresentation.h"
#include "Score.h"

using namespace sf;

int main(){
    RenderWindow window(VideoMode(800, 600), "Score");
    window.setMouseCursorVisible(false);
    //This ensures that the window will refresh at the same speed as the monitor to avoid sampling issues
    window.setVerticalSyncEnabled(true);
    Score score;

    // Increasing the scores  You would call this function when you kill a satelltie or when you kill an enemy
    // As the game loop progresses this score gets bigger in this case increasing by 20
    score.increasePoints(20);
    

    
    ScorePresentation scorePrent(score.getHighestScore());
    
    scorePrent.setScoreMessage(600);
    
    while(window.isOpen()){
        // This two lines creating the increasing highest score. This combination is used when player breaks max score ingame
        score.increasePoints(20);
        scorePrent.setScoreMessage(score.getHighestScore());
        
        // STORESCORE SCORE MUST BE CALLED WHEN EITHER THE PLAYER DIES OR WINS AND IT MUST BE FOLLOWED BY  ALLWAYS
        score.storeScore();// Check the hidden file now with the scores saved
        
        Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  Event::Closed){
                window.close();
                break;
            }
            
            
            
         
        }   
        
        window.clear(Color::Black);      //This sets the window black
        scorePrent.draw(window, 10, 10);
        window.display();               //This applies the changes to the window
        
     }
    
    return 0;
}