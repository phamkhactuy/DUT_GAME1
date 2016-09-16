//
//  SkillItem.cpp
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#include "SkillItem.h"
#include "Constants.h"
#include "MainGameScene.h"
USING_NS_CC;
USING_NS_CC_WIDGET;

SkillItem::SkillItem()
{
    
}

SkillItem::~SkillItem()
{
    
}
bool SkillItem::initSkill(const char *select, const char *skill, const char *un_select, cocos2d::Size size)
{
    if(strcmp(skill, "") == 0)
    {
        return false;
    }
    else
    {
        int number;

    }
    return true;
}
SkillItem* SkillItem::create(const char *select, const char *skill, const char *un_select, cocos2d::Size size)
{
    SkillItem *pRet = new SkillItem();
    if (pRet && pRet->initWith9Sprite(size, select, NULL, NULL) && pRet->initSkill(select, skill, un_select, size))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
