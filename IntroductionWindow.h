#ifndef INTRODUCTIONWINDOW_H
#define INTRODUCTIONWINDOW_H

#include <SFML/Graphics.hpp>
#include "GameCommonData.h"
#include "ExplosionPresentation.h"

using namespace sf;

class IntroductionWindow
{
public:
    IntroductionWindow();
    void run();
    bool isQuitingGame();
    void closeWindow();

private:
    void createWindow();
    void settingUpText();
    void hadleUserDecision(const Event& event);

    bool _isPlayerQuiting;

    Font _font;

    Text _instructionText;
    Text _continueOrQuitText;
    Text _continuePrompt;
    Text _gameRulesText;
    //    Vector2i _windowSize;
    RenderWindow _window;
};

#endif