//
//  SkillLayer.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "SkillLayer.h"
#include "MainGameScene.h"
#include "TileMap.h"
#include "VisibleRect.h"
#include "Constants.h"

USING_NS_CC;
USING_NS_CC_WIDGET;
using namespace std;

static SkillLayer *_functionAction = 0;

SkillLayer* SkillLayer::getInstance()
{
    return _functionAction;
}


SkillLayer::SkillLayer()
{
    _functionAction = this;
}
SkillLayer::~SkillLayer()
{
    
}
bool SkillLayer::init()
{
    
    this->addChild(m_pWindow);
    CLabel* lbleft = CLabel::create();
    lbleft->setString(StringUtils::format("Left  %d",TileMap::getInstance()->getTotalLeft()));
    lbleft->setName("left");
    lbleft->setSystemFontSize(35);
    lbleft->setPosition(VisibleRect::rightBottom() + Vec2(-80, 20));
    lbleft->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbleft);
    
    CLabel* lbright = CLabel::create();
    lbright->setString(StringUtils::format("Right  %d",TileMap::getInstance()->getTotalRight()));
    lbright->setName("right");
    lbright->setSystemFontSize(35);
    lbright->setPosition(VisibleRect::rightBottom() + Vec2(-80, 100));
    lbright->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbright);
    
    CLabel* lbtop = CLabel::create();
    lbtop->setString(StringUtils::format("Top  %d",TileMap::getInstance()->getTotalTop()));
    lbtop->setName("top");
    lbtop->setSystemFontSize(35);
    lbtop->setPosition(VisibleRect::rightBottom() + Vec2(-80, 200));
    lbtop->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbtop);
    
    CLabel* lbbot = CLabel::create();
    lbbot->setString(StringUtils::format("Bot  %d",TileMap::getInstance()->getTotalBot()));
    lbbot->setName("bot");
    lbbot->setSystemFontSize(35);
    lbbot->setPosition(VisibleRect::rightBottom() + Vec2(-80, 300));
    lbbot->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbbot);
    
    CLabel* lbSprings = CLabel::create();
    lbSprings->setString(StringUtils::format("Springs  %d",TileMap::getInstance()->getTotalSprings()));
    lbSprings->setName("springs");
    lbSprings->setSystemFontSize(35);
    lbSprings->setPosition(VisibleRect::rightBottom() + Vec2(-80, 380));
    lbSprings->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbSprings);
    
    CLabel* lbstart = CLabel::create();
    lbstart->setString("start");
    lbstart->setName("start");
    lbstart->setSystemFontSize(35);
    lbstart->setPosition(VisibleRect::rightBottom() + Vec2(-80, 460));
    lbstart->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbstart);
    
    CLabel* lbremove = CLabel::create();
    lbremove->setString("remove");
    lbremove->setName("remove");
    lbremove->setSystemFontSize(35);
    lbremove->setPosition(VisibleRect::rightBottom() + Vec2(-80, 540));
    lbremove->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbremove);
    
    CLabel* lbformatkey = CLabel::create();
    lbformatkey->setString(StringUtils::format("F_K %d - %d ",TileMap::getInstance()->getTotalStar(), TileMap::getInstance()->getTotalKey()));
    lbformatkey->setName("formatkey");
    lbformatkey->setSystemFontSize(35);
    lbformatkey->setPosition(VisibleRect::rightBottom() + Vec2(-80, 600));
    lbformatkey->setOnTouchBeganListener(this, ccw_touchbegan_selector(SkillLayer::onClickItem));
    m_pWindow->addChild(lbformatkey);
    
    return true;
}

void SkillLayer::updateFun(){
    CLabel* lbleft = (CLabel*)m_pWindow->getChildByName("left");
    lbleft->setString(StringUtils::format("Left  %d",TileMap::getInstance()->getTotalLeft()));
    
    CLabel* lbright = (CLabel*)m_pWindow->getChildByName("right");
    lbright->setString(StringUtils::format("Right  %d",TileMap::getInstance()->getTotalRight()));
    
    CLabel* lbtop = (CLabel*)m_pWindow->getChildByName("top");
    lbtop->setString(StringUtils::format("Top  %d",TileMap::getInstance()->getTotalTop()));

    CLabel* lbbot = (CLabel*)m_pWindow->getChildByName("bot");
    lbbot->setString(StringUtils::format("Bot  %d",TileMap::getInstance()->getTotalBot()));
    
    CLabel* lbsprings = (CLabel*)m_pWindow->getChildByName("springs");
    lbsprings->setString(StringUtils::format("Springs  %d",TileMap::getInstance()->getTotalSprings()));
    
    CLabel* lbformatkey = (CLabel*)m_pWindow->getChildByName("formatkey");
    lbformatkey->setString(StringUtils::format("F_K %d - %d ",TileMap::getInstance()->getTotalStar() - TileMap::getInstance()->getCurrenStar(), TileMap::getInstance()->getTotalKey() - TileMap::getInstance()->getCurrenKey()));
    
}

void SkillLayer::onClickItem(Ref* ref){
    
    CLabel*lb = (CLabel*)ref;
    auto st = lb->getName();
    _dir = -1;
    if(st == "left" && TileMap::getInstance()->getTotalLeft() > 0){
        _dir = IDTILE::TILE_LEFT;
    }else if(st == "right" && TileMap::getInstance()->getTotalRight() > 0){
        _dir = IDTILE::TILE_RIGHT;
    }else if (st == "top" && TileMap::getInstance()->getTotalTop() > 0){
        _dir = IDTILE::TILE_TOP;
    }else if(st == "bot" && TileMap::getInstance()->getTotalBot() > 0){
        _dir = IDTILE::TILE_BOT;
    }else if(st == "start"){
        _dir = IDTILE::TILE_START;
        MainGameScene::getInstance()->getMainChar()->setStateChar(stateRun);
    }else if(st == "remove"){
        _dir = IDTILE::TILE_REMOVE;
    }else if(st == "springs" && TileMap::getInstance()->getTotalSprings() > 0){
        _dir = IDTILE::TILE_SPRINGS;
    }
    updateFun();
}



