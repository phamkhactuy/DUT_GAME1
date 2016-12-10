#ifndef __GameSingleton_H__
#define __GameSingleton_H__

#include "cocos2d.h"

class GameSingleton
{
public:
    GameSingleton();
	 ~GameSingleton();
    
    virtual bool init();
    
	static GameSingleton * getInstance(void);
    
    cocos2d::Size _winsize;
    cocos2d::Size _winsizeCustom;
    
    float getScaleFixWith();
    float getScaleFixHeight();
    
    CC_SYNTHESIZE(int, level, Level);
    
};

#endif // __LOADING_SCENE_H__
