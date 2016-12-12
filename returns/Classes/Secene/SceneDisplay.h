//
//  SceneDisplay.h
//  gamebase
//
//  Created by keikan on 5/15/15.
//
//

#ifndef __gamebase__SceneDisplay__
#define __gamebase__SceneDisplay__

#include "cocos2d.h"

typedef enum
{
    INVALID_LAYER_INDEX = -1,
    BASE_LAYER_INDEX = 0,
    GAME_LAYER_INDEX,
    GUI_LAYER_INDEX,
    EFFECT_LAYER_INDEX,
    POPUP_LAYER_INDEX,
    LOADING_LAYER_INDEX,
}LAYER_INDEX;

#define NUMBER_OF_LAYER 6

class SceneDisplay : public cocos2d::Layer
{
public:
    SceneDisplay();
    ~SceneDisplay();
    
    CREATE_FUNC(SceneDisplay);
    
    cocos2d::Layer* baseLayer();
    cocos2d::Layer* gameLayer();
    cocos2d::Layer* guiLayer();
    cocos2d::Layer* loadingLayer();
    cocos2d::Layer* popupLayer();
    cocos2d::Layer* effectLayer();
    cocos2d::Layer* getLayerByIndex(LAYER_INDEX index);
    
private:
    cocos2d::Layer* _arrLayers[NUMBER_OF_LAYER];
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JNIEXPORT void JNICALL Java_com_newwindsoft_basegame_UtilActivity_resultFunc
    (JNIEnv *, jobject, jint);
#endif
};

#endif /* defined(__gamebase__SceneDisplay__) */
