#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameCommonData.h"

using namespace sf;
class CreateWindow
{
public:
    CreateWindow();
    void createWindow();
    RenderWindow getWindow();
    RenderWindow _window;


};

#endif // RENDERWINDOW_H
