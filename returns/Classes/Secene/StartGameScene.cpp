//
//  StartGameScene.cpp
//  gamebase
//
//  Created by NGOCDIEP on 4/16/15.
//
//

#include "StartGameScene.h"
#include "Constants.h"
#include <cocos-widget.h>
#include "VisibleRect.h"
#include "StartGameLayer.h"

USING_NS_CC;
USING_NS_CC_WIDGET;

StartGameScene* StartGameScene::_instance = NULL;

StartGameScene::StartGameScene()
{
    _instance = NULL;
}
StartGameScene::~StartGameScene()
{
    _instance = NULL;
}

Scene* StartGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartGameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartGameScene::init()
{
    
    //set value instance
    _instance = this;
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    createStartLayer();
    
    return true;
}

void StartGameScene::createStartLayer(){
    StartGameLayer* startLayer = StartGameLayer::create();
    this->guiLayer()->addChild(startLayer);
}

void StartGameScene::onClickItem(cocos2d::Ref *ref){
    
}


void StartGameScene::menuCloseCallback(Ref* pSender)
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



