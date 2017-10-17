#include "ExplosionPresentation.h"


ExplosionPresentation::ExplosionPresentation(){}

ExplosionPresentation::ExplosionPresentation(float x, float y)
{
    

    _explosion.setScale(sf::Vector2f(1.5, 1.5));
    _explosion.setPosition(0, 0);
    
    
}


void ExplosionPresentation:: draw(sf::RenderWindow& window){
    _count++;
    if (_count%10 == 0){
 _spriteSheetcount++;
    }
    if(_count == 50){
        _count = 0;
    }
 //flamethrower_0001
 std::string  file = "bolt_sizzle/bolt_sizzle_000";
 
 if (_spriteSheetcount < 10){
     file = "bolt_sizzle/bolt_sizzle_000";
 }else{
           file = "bolt_sizzle/bolt_sizzle_00";

 }
 
    std::ostringstream oss;
    
   oss<<_spriteSheetcount;
   
    file += oss.str();
//    if(_spriteSheetcount >= 3) {
//        _yspriteSheetCount++;
//        _spriteSheetcount = 0;
//    } 
//   if(_yspriteSheetCount >= 3){
//       _yspriteSheetCount = 0;
//    }
 if(!_explosionTexture.loadFromFile(file+".png")) {
        std::cerr << "Error Loading Player Texture";
    }

    _explosion.setTexture(_explosionTexture);
 //   _explosion.setTextureRect(sf::IntRect(64 * _spriteSheetcount, 64*_yspriteSheetCount, 64, 64));
 
    window.draw(_explosion);
  //  std::cout<<_spriteSheetcount<<std::endl;
  if(_spriteSheetcount >=10){
      _spriteSheetcount =1;
  }
   
    
}