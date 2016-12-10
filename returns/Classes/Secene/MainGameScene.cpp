//
//  MainGameScene.cpp
//  gamebase
//
//  Created by NGOCDIEP on 4/14/15.
//
//

#include "MainGameScene.h"
#include "VisibleRect.h"
#include "SkillLayer.h"
#include "ConvertUtils.h"
#include "Constants.h"
#include "GameSingleton.h"

USING_NS_CC;
USING_NS_CC_WIDGET;

MainGameScene* MainGameScene::_instance = NULL;

MainGameScene::MainGameScene()
{
    _instance = NULL;
}
MainGameScene::~MainGameScene()
{
    _instance = NULL;
}

Scene* MainGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainGameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainGameScene::init()
{
    
    //set value instance
    _instance = this;
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    SpriteFrameCache* cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("avatar/Avatar.plist");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    createBackground();
    createMap();
    createSkill();
    createPlayer();
    
    _mainLoop = 0;
    this->scheduleUpdate();
    
    return true;
}

void MainGameScene::createBackground(){
    
    CImageView *image = CImageView::create("Maps/bg_level1.jpg");
    Sprite *sp = Sprite::create("Maps/bg_level1.jpg");
    sp->setPosition(WIN_SIZE.width *0.5, WIN_SIZE.height * 0.5);
    this->addChild(sp,-1);
    
}

void MainGameScene::update(float delta){
    _mainLoop++;
    _mainChar->update(_mainLoop);
    
}

void MainGameScene::createMap(){
    
    //Create map with level
    log("level %d" , GameSingleton::getInstance()->getLevel());
    _map = TileMap::create(GameSingleton::getInstance()->getLevel());
    this->baseLayer()->addChild(_map);
}

void MainGameScene::createSkill(){
    SkillLayer* skillLayer = SkillLayer::create();
    this->guiLayer()->addChild(skillLayer);
}



void MainGameScene::createPlayer()
{
    _mainChar = new Player();
    Vec2 pos = TileMap::getInstance()->getStartPos();
    //Đảo chiều y do hệ toạ độ tilemap khác hệ toạ độ cocos2dx.
//    Vec2 posPlayer = Vec2(pos.x,  fabs(_map->getTileMap()->getContentSize().height - pos.y));
//    posPlayer  +=  Vec2(TILE_SIZE * 0.5, -TILE_SIZE * 0.5);
    _mainChar->setPositionMap(pos);
//    _mainChar->getSpriteChar()->setPosition(posPlayer);
    _mainChar->getSpriteChar()->setAnchorPoint(Vec2(0.5,0.5));
    _mainChar->getSpriteChar()->setScale(0.5, 0.5);
    
    _map->getTileMap()->addChild(_mainChar->getSpriteChar(),1);
    
//    this->gameLayer()->addChild(_mainChar->getSpriteChar(),3);
}

void MainGameScene::menuCloseCallback(Ref* pSender)
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



