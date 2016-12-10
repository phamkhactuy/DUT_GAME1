//
//  StartGameLayer.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "StartGameLayer.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "MainGameScene.h"
#include "StartGameScene.h"
USING_NS_CC;
USING_NS_CC_WIDGET;
using namespace std;

static StartGameLayer *_functionAction = 0;

StartGameLayer* StartGameLayer::getInstance()
{
    return _functionAction;
}


StartGameLayer::StartGameLayer()
{
    _functionAction = this;
}
StartGameLayer::~StartGameLayer()
{
    
}
bool StartGameLayer::init()
{
    
    this->addChild(m_pWindow);
    CLabel* lbStart = CLabel::create();
    lbStart->setString("Start Game");
    lbStart->setName("start");
    lbStart->setSystemFontSize(35);
    lbStart->setPosition(VisibleRect::center() + Vec2(0, 100));
    lbStart->setOnTouchBeganListener(this, ccw_touchbegan_selector(StartGameLayer::onClickItem));
    m_pWindow->addChild(lbStart);
    
    CLabel* lbMenu = CLabel::create();
    lbMenu->setString("Menu Game");
    lbMenu->setName("menu");
    lbMenu->setSystemFontSize(35);
    lbMenu->setPosition(VisibleRect::center() + Vec2(0, 50));
    lbMenu->setOnTouchBeganListener(this, ccw_touchbegan_selector(StartGameLayer::onClickItem));
    m_pWindow->addChild(lbMenu);
    
    CLabel* lbOption = CLabel::create();
    lbOption->setString("Option");
    lbOption->setName("option");
    lbOption->setSystemFontSize(35);
    lbOption->setPosition(VisibleRect::center() + Vec2(0, 0));
    lbOption->setOnTouchBeganListener(this, ccw_touchbegan_selector(StartGameLayer::onClickItem));
    m_pWindow->addChild(lbOption);
    
    CLabel* lbAbout = CLabel::create();
    lbAbout->setString("About");
    lbAbout->setName("about");
    lbAbout->setSystemFontSize(35);
    lbAbout->setPosition(VisibleRect::center() + Vec2(0, -50));
    lbAbout->setOnTouchBeganListener(this, ccw_touchbegan_selector(StartGameLayer::onClickItem));
    m_pWindow->addChild(lbAbout);
    
    CLabel* lbHelp = CLabel::create();
    lbHelp->setString("Help");
    lbHelp->setName("help");
    lbHelp->setSystemFontSize(35);
    lbHelp->setPosition(VisibleRect::center() + Vec2(0, -100));
    lbHelp->setOnTouchBeganListener(this, ccw_touchbegan_selector(StartGameLayer::onClickItem));
    m_pWindow->addChild(lbHelp);
    
    return true;
}

void StartGameLayer::onClickItem(Ref* ref){
    
    CLabel*lb = (CLabel*)ref;
    auto st = lb->getName();
    
    
    if(st == "start"){//Start game
        auto scene = MainGameScene::createScene();
        Director::getInstance()->replaceScene(scene);
    }else if(st == "menu"){
        
    }else if (st == "option"){
        
    }else if(st == "about"){
        
    }else if(st == "help"){
        
    }
    
}



