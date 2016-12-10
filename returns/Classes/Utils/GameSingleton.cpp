

#include "GameSingleton.h"

USING_NS_CC;

static GameSingleton *_instance = NULL;

GameSingleton* GameSingleton::getInstance(void)
{
    if (!_instance)
    {
        _instance = new GameSingleton();
        _instance->init();
    }
    
    return _instance;
}

GameSingleton::GameSingleton()
{
}

GameSingleton::~GameSingleton()
{
    _instance = NULL;
}

bool GameSingleton::init(void)
{

    level = 1;
    return true;
}

float GameSingleton::getScaleFixWith(){
    float f = 1.0f;
    
    float fx = _winsizeCustom.width/_winsize.width;
    float fy = _winsizeCustom.height/_winsize.height;
    
    f = 1 + (fx - fy);
    
    return f;
}

float GameSingleton::getScaleFixHeight(){
    float f = 1.0f;
    
    float fx = _winsizeCustom.width/_winsize.width;
    float fy = _winsizeCustom.height/_winsize.height;
    
    f = 1 + (fy - fx);
    
    return f;
}
