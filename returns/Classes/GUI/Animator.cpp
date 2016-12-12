//
//  Animator.cpp
//  gamebase
//
//  Created by keikan on 9/4/15.
//
//

#include "Animator.h"

//Animator* Animator::_instance = NULL;
//
//Animator* Animator::getInstance()
//{
//    if (!_instance) {
//        _instance = new Animator();
//    }
//    return _instance;
//}

//Animator::Animator()
//{
//    
//}
//
//Animator::~Animator()
//{
//    
//}
USING_NS_CC;

cocos2d::ActionInterval* Animator::jumpIn(cocos2d::Node *node, float delayTime)
{
    node->setScale(0);
    node->setAnchorPoint(Vec2(0.5,0));
    int high = 0.5*node->getContentSize().height;
    auto jumpUp = MoveBy::create(0.3, Vec2(0,high));
    auto jumpDown = MoveBy::create(0.2, Vec2(0,-high));
    
    auto scaleUp = ScaleTo::create(0.25, 0.85, 1.15);
    
    auto scale2 = ScaleTo::create(0.18, 1.07,0.83);
    auto scale3 = ScaleTo::create(0.12, 1);
    
    auto seqSub = Sequence::create(EaseQuarticActionOut::create(scale2), EaseQuarticActionIn::create(scale3), NULL);
    
    
    auto seqUp = Sequence::create(scaleUp, ScaleTo::create(0.05, 1),NULL);
    
    auto spawn = Spawn::create(jumpUp, seqUp, NULL);
    
    auto easeUp = EaseExponentialOut::create(spawn);
    auto easeDown = EaseExponentialIn::create(jumpDown);
    
    auto seq = Sequence::create(DelayTime::create(delayTime), easeUp, easeDown, seqSub, NULL);
    
    return seq;
}

cocos2d::ActionInterval* Animator::jumpOut(cocos2d::Node *node, float delayTime)
{
    node->setScale(1);
    node->setAnchorPoint(Vec2(0.5,0));
    
    int high = 0.5*node->getContentSize().height;
    
    auto jumpUp = MoveBy::create(0.28, Vec2(0,high));
    auto jumpDown = MoveBy::create(0.2, Vec2(0,-high));
    
    auto scaleUp = ScaleTo::create(0.23, 0.85, 1.15);
    
    auto scale2 = ScaleTo::create(0.18, 1.07,0.83);
    auto scale3 = ScaleTo::create(0.12, 1);
    
    auto seqSub = Sequence::create(EaseQuarticActionOut::create(scale2), EaseQuarticActionIn::create(scale3), NULL);
    
    
    auto seqUp = Sequence::create(scaleUp, ScaleTo::create(0.05, 1),NULL);
    
    auto spawn = Spawn::create(jumpUp, seqUp, NULL);
    
    auto easeUp = EaseExponentialOut::create(spawn);
    auto easeDown = EaseExponentialIn::create(jumpDown);
    auto spawnDown = Spawn::create(ScaleTo::create(0.2, 0), easeDown, NULL);
    
    auto seq = Sequence::create(DelayTime::create(delayTime),seqSub, easeUp, spawnDown, NULL);
    
    return seq;
}

void Animator::multiJumpIn(float delayTime, cocos2d::Node *node, ...)
{
    va_list params;
    va_start(params, node);
    
    Node* prev = node;
    
    int count = 0;
    
    while (prev)
    {
        prev->runAction(Animator::jumpIn(prev, delayTime*count));
        prev = va_arg(params, Node*);
        count++;
    }
    
    
    va_end(params);
}

void Animator::multiJumpIn(float delayTime, const cocos2d::Vector<cocos2d::Node*>& arrayOfNodes)
{
    auto count = 0;
    
    if (!arrayOfNodes.empty())
    {
        for (auto& node : arrayOfNodes)
        {
            node->runAction(Animator::jumpIn(node,delayTime*count));
            count++;
        }

    }
    
}
