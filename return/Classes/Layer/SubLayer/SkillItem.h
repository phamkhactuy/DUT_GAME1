//
//  SkillItem.h
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#ifndef __gamebase__SkillItem__
#define __gamebase__SkillItem__

#include <cocos-widget.h>
#include <cocos2d.h>

class SkillItem : public cocos2d::cocoswidget::CButton
{
public:
    SkillItem();
    ~SkillItem();
    static SkillItem* create(const char* select, const char* skill, const char* un_select, cocos2d::Size size);
private:
    bool initSkill(const char* select, const char* skill, const char* un_select, cocos2d::Size size);
    CC_SYNTHESIZE(cocos2d::cocoswidget::CLabel*, _labelSkill, LabelSkill);
};
#endif /* defined(__gamebase__SkillItem__) */
