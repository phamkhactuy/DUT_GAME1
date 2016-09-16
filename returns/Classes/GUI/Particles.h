//
//  Particles.h
//  gamebase
//
//  Created by NGOCDIEP on 7/30/15.
//
//

#ifndef __gamebase__Particles__
#define __gamebase__Particles__

#include "cocos2d.h"
//! @brief An snow particle system
class CParticles : public cocos2d::ParticleSystemQuad
{
public:
    static CParticles* create();
    static CParticles* createWithTotalParticles(int numberOfParticles);
    
CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    CParticles(){}
    /**
     * @js NA
     * @lua NA
     */
    virtual ~CParticles(){}
    
    bool init(){ return initWithTotalParticles(700); }
    virtual bool initWithTotalParticles(int numberOfParticles);
    
private:
    CC_DISALLOW_COPY_AND_ASSIGN(CParticles);
};
#endif /* defined(__gamebase__Particles__) */
