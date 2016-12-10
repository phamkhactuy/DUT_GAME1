//
//  DataObject.cpp
//  game1
//
//  Created by NGOCDIEP on 11/3/15.
//
//

#include "DataObject.h"

USING_NS_CC;

DataObject::DataObject(){
    
    frameChar = 1;
    
    frDie = 0;
    frJump = 0;
    frRun = 0;
    frIdle = 0;
    stopAllAction = 0;
    
    spriteChar = Sprite::createWithSpriteFrameName("Player_1_1_1_1.png");
}

DataObject::~DataObject(){
    
}

void DataObject::doUpdateFrame(int loop){
    if(stopAllAction == 0){
    switch (stateChar) {
        case stateDie:
            doFrameDie(loop);
            break;
        case stateIdle:
            doFrameIdle();
            break;
        case stateJump:
            doFrameJump();
            break;
        case stateRun:
            doFrameRun();
            break;

    }
    }
}
void DataObject::doUpdatePos(){
    if(stopAllAction == 0){
    switch (stateChar) {
        case stateJump:
            doPosJump();
            break;
        case stateRun:
            doPosRun();
            break;
            
    }
    }
}

void DataObject::doPosJump(){
    Vec2 dir = Vec2::ZERO;
    switch (this->getDirChar()) {
        case dirLeft:
            dir = Vec2(-this->getDeltaMove().x * 2, 0);
            //spriteChar->setScale(-1,0);
            break;
        case dirRight:
            dir = Vec2(this->getDeltaMove().x * 2, 0);
            //spriteChar->setScale(-1,0);
            break;
        case dirTop:
            dir = Vec2(0, this->getDeltaMove().y * 2);
            //spriteChar->setScale(0,1);
            break;
        case dirBot:
            dir = Vec2(0, -this->getDeltaMove().y * 2);
            //spriteChar->setScale(0,-1);
            break;
        default:
            break;
    }
    
    spriteChar->setPosition(spriteChar->getPosition() + dir);
}

void DataObject::doPosRun(){
    Vec2 dir = Vec2::ZERO;
    switch (this->getDirChar()) {
        case dirLeft:
            dir = Vec2(-this->getDeltaMove().x, 0);
            //spriteChar->setScale(-1,0);
            break;
        case dirRight:
            dir = Vec2(this->getDeltaMove().x, 0);
            //spriteChar->setScale(-1,0);
            break;
        case dirTop:
            dir = Vec2(0, this->getDeltaMove().y);
            //spriteChar->setScale(0,1);
            break;
        case dirBot:
            dir = Vec2(0, -this->getDeltaMove().y);
            //spriteChar->setScale(0,-1);
            break;
        default:
            break;
    }
    
    spriteChar->setPosition(spriteChar->getPosition() + dir);

}

void DataObject::doFrameDie(int loop){
    frameChar++;
    if(frameChar > frDie){
        frameChar = 1;
        stopAllAction = loop;
    }
    
    int dir = getBaseDir(dirChar);
    std::string key = cocos2d::StringUtils::format("%s_%d_%d_%d_%d.png", idChar, levelChar, dir, stateRun, frameChar);

    spriteChar->setSpriteFrame(this->getSpriteFrameByKey(key));
}

void DataObject::doFrameIdle(){
    frameChar++;
    if(frameChar > frIdle)
        frameChar = 1;
    
    int dir = getBaseDir(dirChar);
    std::string key = cocos2d::StringUtils::format("%s_%d_%d_%d_%d.png", idChar, levelChar, dir, stateRun, frameChar);

    spriteChar->setSpriteFrame(this->getSpriteFrameByKey(key));
    
}

void DataObject::doFrameJump(){
    frameChar++;
    if(frameChar > frJump)
        frameChar = 1;
    
    int dir = getBaseDir(dirChar);
    std::string key = cocos2d::StringUtils::format("%s_%d_%d_%d_%d.png", idChar, levelChar, dir, stateRun, frameChar);

    spriteChar->setSpriteFrame(this->getSpriteFrameByKey(key));
}

void DataObject::doFrameRun(){
    
    frameChar++;
    if(frameChar > frRun)
        frameChar = 1;
    
    int dir = getBaseDir(dirChar);
    std::string key = cocos2d::StringUtils::format("%s_%d_%d_%d_%d.png", idChar, levelChar, dir, stateRun, frameChar);

    spriteChar->setSpriteFrame(this->getSpriteFrameByKey(key));
    
}

int DataObject::getBaseDir(int dirChar){
    int dir = dirChar;
    if(DIR_BASE == 2){
        if(dirChar == dirRight || dirChar == dirLeft)
            dir = dirRight;
        if(dirChar == dirTop || dirChar == dirBot)
            dir = dirTop;
    }else if(DIR_BASE == 1){
        //Game chi co 1 huong co ban
        dir = dirRight;
    }else if(DIR_BASE == 4){
        //Game co 4 huong co ban
    }
    return dir;
}


