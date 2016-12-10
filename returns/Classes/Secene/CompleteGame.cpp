//
//  SplashScene.cpp
//  gamebase
//
//  Created by NGOCDIEP on 4/16/15.
//
//

#include "CompleteGame.h"
#include "GameWinLayer.h"
#include "GameOverLayer.h"

USING_NS_CC;

Scene* CompleteGame::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CompleteGame::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CompleteGame::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    createGameWinLayer();
    
    return true;
}

void CompleteGame::createGameWinLayer(){
    GameWinLayer *layer = GameWinLayer::create();
    this->guiLayer()->addChild(layer);
}


void CompleteGame::createGameOverLayer(){

}

void CompleteGame::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
