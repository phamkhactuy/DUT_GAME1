//  gamebase
//
//  Created by NgocDiep on 7/8/15.
//
//
#ifndef __NATIVE_UTILS_H__
#define __NATIVE_UTILS_H__


#include "cocos2d.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNIHelpers.h"
#endif

class NativeUtils
{
public:
	/*
	* Google play game services methods
	*/
	static bool isSignedIn();
	static void signIn();
	static void signOut();
	static void submitScore(const char* leaderboardID, long score);
	static void unlockAchievement(const char* achievementID);
	static void incrementAchievement(const char* achievementID, int numSteps);
    static void incrementPercentageAchievement(const char *achievementID, float percentage);
	static void showAchievements();
	static void showLeaderboards();
	static void showLeaderboard(const char* leaderboardID);
    
    static void initAd();
    static void showAd();
    static void hideAd();
    static void initialGCM();
    static void rateApp();
    
    static void inappBilling(const char* inappID);
    static void pushNotification( const char* content, int time);
    
    static void showAdBuddiz();
    
    static void sendAnalytics(const char* screen);
    
    static void shareOnFacebook(long score, int level, int obstacles);
    static void shareOnTwitter(char* msg, char* url, char* image= "" , int flag = 1);
    static void shareOnFacebook(char* content, char* url = "", char* image = "" , int flag = 1);
    static void shareOnTwitter(long score, int level, int obstacles);
    static void killApp();
	
	/*
	* Ouya connection
	*/
	

};

#endif
