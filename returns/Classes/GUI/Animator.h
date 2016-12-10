//
//  Animator.h
//  gamebase
//
//  Created by keikan on 9/4/15.
//
//

#ifndef __gamebase__Animator__
#define __gamebase__Animator__

#include "cocos2d.h"

class Animator
{
public:
//    static Animator* getInstance();
    
    static cocos2d::ActionInterval* jumpIn(cocos2d::Node* node, float delayTime = 0);
    static cocos2d::ActionInterval* jumpOut(cocos2d::Node* node, float delayTime = 0);
    static void multiJumpIn(float delayTime, cocos2d::Node *node, ...);
    static void multiJumpIn(float delayTime, const cocos2d::Vector<cocos2d::Node*>& arrayOfNodes);
    
private:
//    static Animator* _instance;
protected:
//    Animator();
//    ~Animator();
    
};

#endif /* defined(__gamebase__Animator__) */
