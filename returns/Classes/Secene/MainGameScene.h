//
//  MainGameScene.h
//  gamebase
//
//  Created by NGOCDIEP on 4/14/15.
//
//

#ifndef __gamebase__MainGameScene__
#define __gamebase__MainGameScene__

#include "SceneDisplay.h"
#include "TileMap.h"
#include "Player.h"

class MainGameScene : public SceneDisplay
{
    
public:
    MainGameScene();
    ~MainGameScene();
    
    static MainGameScene* _instance;
    
    static MainGameScene * getInstance(){return _instance;};
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(MainGameScene);
    
    CC_SYNTHESIZE(int, _mainLoop, MainLoop);
    
    void createBackground();
    void createMap();
    void createSkill();
    void createPlayer();
    
    void update(float delta);
    
    CC_SYNTHESIZE(TileMap*, _map, Map);
    CC_SYNTHESIZE(Player*, _mainChar, MainChar);
    
    
    
};


#endif /* defined(__gamebase__MainGameScene__) */
