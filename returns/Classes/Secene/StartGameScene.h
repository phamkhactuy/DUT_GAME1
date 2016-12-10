//
//  StartGameScene.h
//  gamebase
//
//  Created by NGOCDIEP on 4/16/15.
//
//

#ifndef __gamebase__StartGameScene__
#define __gamebase__StartGameScene__

#include "SceneDisplay.h"


class StartGameScene : public SceneDisplay
{
    
private:
    static StartGameScene* _instance;
    void onClickItem(Ref* ref);
    void createStartLayer();
    
public:
    
    StartGameScene();
    ~StartGameScene();
    
    static StartGameScene * getInstance(){return _instance;};
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(StartGameScene);
    
};
#endif /* defined(__gamebase__StartGameScene__) */
