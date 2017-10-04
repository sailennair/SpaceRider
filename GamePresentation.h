#ifndef GAMEPRESENTATION_H
#define GAMEPRESENTATION_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerPresentation.h"
#include "GameLogic.h"
#include "GameCommonData.h"
#include <memory>
#include "PlayerBulletPresentation.h"

using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

using namespace std;

class GamePresentation
{
public:
    GamePresentation();
    
    void renderSprite(RenderWindow &window);
    
    void upDatePosition();
    
    void upDatePlayerBulletPresentation();
    
    
   // shared_ptr<GameLogic> gameLogic_shared_pointer(new GameLogic());
   
     shared_ptr<GameLogic> gameLogic_shared_pointer;
     
     //= make_shared<GameLogic>;
    //auto gameLogic_shared_pointer = make_shared<GameLogic>;
    
private:
    PlayerPresentation _playerPresentation;
    
    vector<PlayerBulletPresentation> playerBulletPresentationVector;
    //GameLogic _gameLogic;
    
    

};

#endif // GAMEPRESENTATION_H
