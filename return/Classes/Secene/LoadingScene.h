//
//  LoadingScene.h
//  gamebase
//
//  Created by NGOCDIEP on 4/16/15.
//
//

#ifndef __gamebase__LoadingScene__
#define __gamebase__LoadingScene__

#include "SceneDisplay.h"

class LoadingScene: public SceneDisplay
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LoadingScene);
};

#endif /* defined(__gamebase__LoadingScene__) */
