////
////  GameCenterInterface.h
////  gamebase
////
////  Created by Hisoka on 5/27/15.
////
////
//
#ifndef __gamebase__HelperUtilsInterface__
#define __gamebase__HelperUtilsInterface__

#include "cocos2d.h"


class HelperUtilsInterface{
public:
    static void GameCenterPostScore(int score);
    static void GameCenterLogin();
    static bool GameCenterCheckLogin();
    static void GameCenterShowLeaderboard();
    static void GameCenterShowAchievements();
    static bool GameCenterCheckLAvaiable();
    static void ShareFBTT(int type, std::string message, std::string url, std::string imgUrl);
    static bool checkFBAvaiable();
    static bool checkTTAvaiable();
    static bool checkShareFBSuccess();
    static bool checkShareTTSuccess();
};
#endif /* defined(__gamebase__GameCenterInterface__) */
