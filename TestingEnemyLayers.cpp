#include "EnemyLogic.h"
#include "EnemyPresentation.h"
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

int main(){
    
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int PI = 3.14159265;
    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Testing Enemy Layers");
    
    EnemyLogic enemyLogic(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 20, 20, 0.89);
    EnemyPresentation enemyPresentation(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  sf::Event::Closed){
                window.close();
                break;
            }
            
            
        }
        //
        
        enemyLogic.move();
        
        window.clear();
        if(enemyPresentation.isOutOfScreen(WINDOW_WIDTH, WINDOW_HEIGHT, enemyLogic.getXPosition(), enemyLogic.getYPosition())){
           enemyLogic.moveToCenter(WINDOW_WIDTH/2,  WINDOW_HEIGHT/2, 0.89);
           
        }
        enemyPresentation.draw(window, enemyLogic.getXPosition(), enemyLogic.getYPosition(), enemyLogic.getScale());
        window.display();
        std::cout << std::endl;
        std::cout << "Enemy x Pos" <<enemyLogic.getXPosition() << std::endl;
    }
        
    return 0;
}