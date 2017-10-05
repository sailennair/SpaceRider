#include "EnemyLogic.h"

EnemyLogic::EnemyLogic( int initalXposition, int initalYposition, float theta) {
  
   _xpos = CenterXGameWindow;
   _ypos = CenterYGameWindow;
   _theta = theta;
   _initialXposition = CenterXGameWindow;
   _initialYposition = CenterXGameWindow;
  // createEnemyBullet();
   
   
   EnemyBulletLogic enemyBulletLogic{getXposition(),getYposition(),getAngleofRotation()};
  _enemyBulletLogic = enemyBulletLogic;
  
}

void EnemyLogic::move(){
    _xpos += _initialXposition*cos(_theta)*_enemySpeed;
    _ypos += _initialYposition*sin(_theta)*_enemySpeed;
    _enemyBulletLogic.move();
    
   // std::cout << _enemyBulletLogic.getXposition() << "   " << _enemyBulletLogic.getYposition() << std::endl;
}

float EnemyLogic::getAngleofRotation(){
    return _theta;
}

bool EnemyLogic::isAlive(){
    return _life;
}

void EnemyLogic::reduceHealth(int _damage){
    _health -= _damage;
}

float EnemyLogic::getXposition(){
    return _xpos;
}

float EnemyLogic::getYposition(){
    return _ypos;
}

//EnemyBulletLogic EnemyLogic::createEnemyBullet(){
//     EnemyBulletLogic enemyBulletLogic( getXposition() ,getYposition() ,getAngleofRotation());
//     return enemyBulletLogic;
//}