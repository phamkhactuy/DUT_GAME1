//
//  SceneDisplay.cpp
//  gamebase
//
//  Created by keikan on 5/15/15.
//
//

#include "SceneDisplay.h"
USING_NS_CC;

SceneDisplay::SceneDisplay()
{
    //create layer
    cocos2d::Layer * baseLayer = cocos2d::Layer::create();
    baseLayer->setName("base");
    baseLayer->setTag(LAYER_INDEX::BASE_LAYER_INDEX);
    _arrLayers[BASE_LAYER_INDEX] = baseLayer;
    
    cocos2d::Layer * gameLayer = cocos2d::Layer::create();
    gameLayer->setTag(LAYER_INDEX::GAME_LAYER_INDEX);
    gameLayer->setName("game");
    _arrLayers[GAME_LAYER_INDEX] = gameLayer;
    
    cocos2d::Layer * effectLayer = cocos2d::Layer::create();
    effectLayer->setTag(LAYER_INDEX::EFFECT_LAYER_INDEX);
    effectLayer->setName("effect");
    _arrLayers[EFFECT_LAYER_INDEX] = effectLayer;
    
    cocos2d::Layer * guiLayer = cocos2d::Layer::create();
    guiLayer->setTag(LAYER_INDEX::GUI_LAYER_INDEX);
    guiLayer->setName("gui");
    _arrLayers[GUI_LAYER_INDEX] = guiLayer;
    
    cocos2d::Layer * popupLayer = cocos2d::Layer::create();
    popupLayer->setTag(LAYER_INDEX::POPUP_LAYER_INDEX);
    popupLayer->setName("popup");
    _arrLayers[POPUP_LAYER_INDEX] = popupLayer;
    
    cocos2d::Layer * loadingLayer = cocos2d::Layer::create();
    loadingLayer->setTag(LAYER_INDEX::LOADING_LAYER_INDEX);
    loadingLayer->setName("loading");
    _arrLayers[LOADING_LAYER_INDEX] = loadingLayer;
    
    
    //Add child layer
    
    this->addChild(baseLayer,0);
    this->addChild(gameLayer,1);
    this->addChild(effectLayer,2);
    this->addChild(guiLayer,3);
    this->addChild(popupLayer,4);
    this->addChild(loadingLayer,5);

}
SceneDisplay::~SceneDisplay()
{
}

cocos2d::Layer* SceneDisplay::getLayerByIndex(LAYER_INDEX index)
{
    return _arrLayers[index];
}

cocos2d::Layer * SceneDisplay::baseLayer()
{
    return _arrLayers[BASE_LAYER_INDEX];
}
cocos2d::Layer * SceneDisplay::gameLayer()
{
    return _arrLayers[GAME_LAYER_INDEX];
}
cocos2d::Layer * SceneDisplay::effectLayer()
{
    return _arrLayers[EFFECT_LAYER_INDEX];
}
cocos2d::Layer * SceneDisplay::guiLayer()
{
    return _arrLayers[GUI_LAYER_INDEX];
}
cocos2d::Layer * SceneDisplay::popupLayer()
{
    return _arrLayers[POPUP_LAYER_INDEX];
}
cocos2d::Layer * SceneDisplay::loadingLayer()
{
    return _arrLayers[LOADING_LAYER_INDEX];
}


#ifdef __cplusplus
extern "C" {
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    
    
    JNIEXPORT void JNICALL Java_com_newwindsoft_basegame_UtilActivity_resultFunc(JNIEnv *env, jobject obj, jint flag)
    {
        int fl = (int)flag;
    }
#endif
#ifdef __cplusplus
}
#endif


