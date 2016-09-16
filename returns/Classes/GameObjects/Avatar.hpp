//
//  Avatar.hpp
//  game1
//
//  Created by NGOCDIEP on 11/3/15.
//
//

#ifndef Avatar_hpp
#define Avatar_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "AvatarConfig.h"

class Avatar{
    
public:
    Avatar();
    ~Avatar();
    //Key : idChar_level_dir_state_frame.
    cocos2d::SpriteFrame* getSpriteFrameByKey(std::string idChar, int level, int  dir, int state, int frame);
    cocos2d::SpriteFrame* getSpriteFrameByKey(std::string avatarKey);
};

#endif /* Avatar_hpp */
