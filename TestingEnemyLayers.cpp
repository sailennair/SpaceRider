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
    
    EnemyLogic enemyLogic(400, 300, 20, 20, PI/3);
    EnemyPresentation enemyPresentation(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
           
            if(event.type ==  sf::Event::Closed){
                window.close();
                break;
            }
            
        }
        
        enemyLogic.move();
        window.clear();
        if(!enemyPresentation.isOutOfScreen(WINDOW_WIDTH, WINDOW_HEIGHT, enemyLogic.getXPosition(), enemyLogic.getYPosition())){
            enemyPresentation.draw(window, enemyLogic.getXPosition(), enemyLogic.getYPosition());
        }
        window.display();
        //cout << x << "  " << y << endl;
    }
        
    return 0;
}