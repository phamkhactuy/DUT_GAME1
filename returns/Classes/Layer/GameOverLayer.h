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


class GameOverLayer: public LayerDisplay
{
public:
    GameOverLayer();
    ~GameOverLayer();
    CREATE_FUNC(GameOverLayer);
    
    CC_SYNTHESIZE(int, _dir, Dir);//Function action
    
    void updateFun();
    static GameOverLayer* getInstance();
private:
    bool init() override;
    void onClickItem(Ref* ref);

};
#endif /* defined(__gamebase__SkillLayer__) */
