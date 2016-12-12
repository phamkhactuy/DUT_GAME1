//
//  DataObject.h
//  game1
//
//  Created by NGOCDIEP on 11/3/15.
//
//

#ifndef DataObject_h
#define DataObject_h

#include <stdio.h>
#include "Avatar.h"

class DataObject : public Avatar{
    
public:
    DataObject();
    ~DataObject();
    
    CC_SYNTHESIZE(char*, idChar, IdChar);
    CC_SYNTHESIZE(int, levelChar, LevelChar);
    CC_SYNTHESIZE(int, dirChar, DirChar);
    CC_SYNTHESIZE(int, stateChar, StateChar);
    CC_SYNTHESIZE(int, frameChar, FrameChar);
    CC_SYNTHESIZE(cocos2d::Vec2, deltaMove, DeltaMove);
    CC_SYNTHESIZE(cocos2d::Sprite*, spriteChar, SpriteChar);
    CC_SYNTHESIZE(int, stopAllAction, StopAllAction);
    
    CC_SYNTHESIZE(int, frIdle, FrIdle);// So frame thuc hien animation Idle
    CC_SYNTHESIZE(int, frRun, FrRun);// So frame thuc hien animation Run
    CC_SYNTHESIZE(int, frJump, FrJump);// So frame thuc hien animation Jump
    CC_SYNTHESIZE(int, frDie, FrDie);// So frame thuc hien animation Die
    
    void doUpdateFrame(int loop);
    void doUpdatePos();
    void doFrameRun();
    void doFrameIdle();
    void doFrameJump();
    void doFrameDie(int loop);
    
    void doPosRun();
    void doPosJump();
    
private:
    int getBaseDir(int dirChar);
};

#endif /* DataObject_h */
