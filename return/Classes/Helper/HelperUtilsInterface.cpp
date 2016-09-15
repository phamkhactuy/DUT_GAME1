////
////  GameCenterInterface.cpp
////  gamebase
////
////  Created by Hisoka on 5/27/15.
////
////

#include "HelperUtilsInterface.h"
#include "NativeUtils.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
void postFacebook(char* msg, char* url,char* imgUrl);
void postTwitter(char* msg, char* url, char* imgUrl);
bool checkGameCenter(); //check gamecenter login
void loginGameCenter();//gamecenter login
void changeScore(int score);//change score
void showGameLeaderboard();
void showGameAchievements();
bool checkFBTT(int type);
#endif
void HelperUtilsInterface::GameCenterPostScore(int score)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    changeScore(score);
#endif
}
void HelperUtilsInterface::GameCenterLogin()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    loginGameCenter();
#endif
}
bool HelperUtilsInterface::GameCenterCheckLogin()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#endif
    return true;
}
void HelperUtilsInterface::GameCenterShowLeaderboard()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    showGameLeaderboard();
#endif
}
void HelperUtilsInterface::GameCenterShowAchievements()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    showGameAchievements();
#endif
}
bool HelperUtilsInterface::GameCenterCheckLAvaiable(){
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return checkGameCenter();
#endif
}
void HelperUtilsInterface::ShareFBTT(int type, std::string message, std::string url, std::string imgUrl)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    if(type == 1){
        NativeUtils::shareOnFacebook(90, 10, 1);
    } else {
        NativeUtils::shareOnTwitter(90, 10, 1);
    }
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (type == 1) {
        //char a[25] = message.c_str();
        postFacebook((char *)message.c_str(), (char *)url.c_str(),(char *)imgUrl.c_str());
    }
    else
    {
        postTwitter((char *)message.c_str(), (char *)url.c_str(),(char *)imgUrl.c_str());
    }
#endif
}
bool HelperUtilsInterface::checkFBAvaiable()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return checkFBTT(1);
#endif
    
}
bool HelperUtilsInterface::checkTTAvaiable()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return checkFBTT(2);
#endif
#endif
}
bool HelperUtilsInterface::checkShareFBSuccess(){return true;}
bool HelperUtilsInterface::checkShareTTSuccess(){return true;}
