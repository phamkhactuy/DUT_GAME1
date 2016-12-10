//
//  Avatar.cpp
//  game1
//
//  Created by NGOCDIEP on 11/3/15.
//
//

#include "Avatar.h"

USING_NS_CC;

Avatar::Avatar(){
    
}
Avatar::~Avatar(){
    
}

SpriteFrame* Avatar::getSpriteFrameByKey(std::string idChar, int level, int dir, int state, int frame){
    
    std::string str = StringUtils::format("%s_%d_%d_%d_%d.png", idChar.c_str(), level, dir, state, frame);
    log("avatar %s", str.c_str());
    return SpriteFrameCache::getInstance()->getSpriteFrameByName(str);

}

SpriteFrame* Avatar::getSpriteFrameByKey(std::string avatarKey){
    return SpriteFrameCache::getInstance()->getSpriteFrameByName(avatarKey);
    
}
