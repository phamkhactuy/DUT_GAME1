//
//  Player.hpp
//  game1
//
//  Created by NGOCDIEP on 11/4/15.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "DataObject.hpp"

class Player : public DataObject{
    
public:
    Player();
    ~Player();

    void update(int loop);
    void setPositionMap(cocos2d::Vec2 pos);
    
private:
    void logic(cocos2d::Vec2 posMap, int loop);
    void moveCave(int idTile, cocos2d::Vec2 pos, int loop);
    void moveOneStep(cocos2d::Vec2 pos);
    void gameWin();
    
    cocos2d::Vec2 _posOrigin;
    int _flagCave;
    
};
#endif /* Player_hpp */
