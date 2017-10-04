#include "CreateWindow.h"

CreateWindow::CreateWindow()
{
}

 void CreateWindow::createWindow(){
       sf::RenderWindow _window(sf::VideoMode(GameXWindow,GameYWindow), "My Window");

        _window.setVerticalSyncEnabled(true);
 }
 

