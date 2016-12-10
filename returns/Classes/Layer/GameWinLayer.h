//
//  GameWinLayer.h
//  gamebase
//
//  Created by NGOCDIEP on 6/24/15.
//
//

#ifndef __gamebase__SkillLayer__
#define __gamebase__SkillLayer__

#include "LayerDisplay.h"


class GameWinLayer: public LayerDisplay
{
public:
    GameWinLayer();
    ~GameWinLayer();
    CREATE_FUNC(GameWinLayer);
    
    CC_SYNTHESIZE(int, _dir, Dir);//Function action
//    static SkillLayer* create();
    
    void updateFun();
    static GameWinLayer* getInstance();
private:
    bool init() override;
    void onClickItem(Ref* ref);

};
#endif /* defined(__gamebase__SkillLayer__) */
