//
//  LayerDisplay.h
//  gamebase
//
//  Created by NgocDiep on 5/12/15.
//
//

#ifndef __gamebase__LayerDisplay__
#define __gamebase__LayerDisplay__

#include <cocos-widget.h>
#include "cocos2d.h"

typedef enum
{
    NONE = 0,
    FADE_IN,
    FADE_OUT,
    FADE_TO,
}EF_LAYER;

class LayerDisplay : public cocos2d::Layer
{
public:
    LayerDisplay();
    ~LayerDisplay();
    
    CREATE_FUNC(LayerDisplay);
    
    cocos2d::cocoswidget::CWidgetWindow* m_pWindow;
    
    void setShow(bool show = true, int flag = EF_LAYER::NONE);
    void setPos(cocos2d::Vec2 pos, int flag = EF_LAYER::NONE);
};

#endif /* defined(__gamebase__LayerDisplay__) */
