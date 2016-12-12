//
//  StartGameLayer.h
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#ifndef __gamebase__SkillLayer__
#define __gamebase__SkillLayer__

#include "LayerDisplay.h"


class StartGameLayer: public LayerDisplay
{
public:
    StartGameLayer();
    ~StartGameLayer();
    CREATE_FUNC(StartGameLayer);
    
    CC_SYNTHESIZE(int, _dir, Dir);//Function action
//    static SkillLayer* create();
    
    void updateFun();
    static StartGameLayer* getInstance();
private:
    bool init() override;
    void onClickItem(Ref* ref);

};
#endif /* defined(__gamebase__SkillLayer__) */
