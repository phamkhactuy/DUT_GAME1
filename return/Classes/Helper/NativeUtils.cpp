//  gamebase
//
//  Created by NgocDiep on 7/8/15.
//
//
#include "NativeUtils.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include <android/log.h>
#define CLASS_NAME "com/newwindsoft/basegame/NativeUtils"
#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "PlayGameSingleton.h"
#endif

using namespace cocos2d;

#pragma mark - Sign in and Sign out.
bool NativeUtils::isSignedIn()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return JniHelpers::jniCommonBoolCall(
                                         "isSignedIn",
                                         CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return PlayGameSingleton::sharedInstance().isSignedIn();
#endif
    
    return false;
}

void NativeUtils::signIn()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "gameServicesSignIn",
                                  CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().authenticate();
#endif
}

void NativeUtils::signOut()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "gameServicesSignOut",
                                  CLASS_NAME);
#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().signOut();
#endif
}

#pragma mark - Submit score and achievements.
void NativeUtils::submitScore(const char* leaderboardID, long score)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "submitScore",
                                  CLASS_NAME,
                                  leaderboardID,
                                  score);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().submitScore(score, leaderboardID);
#endif
}

void NativeUtils::unlockAchievement(const char* achievementID)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "unlockAchievement",
                                  CLASS_NAME,
                                  achievementID);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().unlockAchievement(achievementID);
#endif
}

void NativeUtils::incrementAchievement(const char* achievementID, int numSteps)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "incrementAchievement",
                                  CLASS_NAME,
                                  achievementID,
                                  numSteps);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().incrementAchievement(numSteps, achievementID);
#endif
}

void NativeUtils::incrementPercentageAchievement(const char *achievementID, float percentage)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().incrementPercentageAchievement(percentage, achievementID);
#endif
}

#pragma mark - Show achievements, leaderboards and single leaderboard.
void NativeUtils::showAchievements()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "showAchievements",
                                  CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().showAchievements();
#endif
}

void NativeUtils::showLeaderboards()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "showLeaderboards",
                                  CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().showLeaderboards();
#endif
    
}

void NativeUtils::showLeaderboard(const char* leaderboardID)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "showLeaderboard",
                                  CLASS_NAME,
                                  leaderboardID);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().showSingleLeaderboard(leaderboardID);
#endif
}

void NativeUtils::sendAnalytics(const char *screen)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "sendAnalytics",
                                  CLASS_NAME,
                                  screen);
#endif
}

void NativeUtils::initAd()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().initAd();
#endif
}

void NativeUtils::showAd()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "showAd",
                                  CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().showAd();
#endif
}

void NativeUtils::initialGCM()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "initialGCM",
                                  CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().showAd();
#endif
}

void NativeUtils::hideAd()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "hideAd",
                                  CLASS_NAME);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().hideAd();
#endif
}

void NativeUtils::rateApp()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "rateApp",
                                  CLASS_NAME);
#endif
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().rateApp();
#endif
}

void NativeUtils::showAdBuddiz()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "showAdBuddiz",
                                  CLASS_NAME);
#endif
}
void NativeUtils::shareOnTwitter(char* msg, char* url, char* image, int flag)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "shareOnTwitter",
                                  CLASS_NAME,
                                  msg,flag);//todo
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
      PlayGameSingleton::sharedInstance().shareOnTwitter(msg, url, image);
#endif
}

void NativeUtils::shareOnTwitter(long score, int level, int obstacles)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "shareOnTwitter",
                                  CLASS_NAME,
                                  level, score, obstacles);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //    PlayGameSingleton::sharedInstance().shareOnTwitter(score, level, obstacles);
#endif
}
void NativeUtils::shareOnFacebook(char* content, char* url, char* image, int flag)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "shareOnFacebook",
                                  CLASS_NAME,
                                  content, flag);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().shareOnFacebook(content, url, image);
#endif
}
void NativeUtils::shareOnFacebook(long score, int level, int obstacles)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "shareOnFacebook",
                                  CLASS_NAME,
                                  level, score, obstacles);
#endif

#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    PlayGameSingleton::sharedInstance().shareOnFacebook(score, level, obstacles);
#endif
}

void NativeUtils::killApp()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "killApp",
                                  CLASS_NAME);
#endif
}

void NativeUtils::inappBilling(const char* inappID)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "inappBilling",
                                  CLASS_NAME,
                                  inappID);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //    PlayGameSingleton::sharedInstance().showSingleLeaderboard(leaderboardID);
#endif
}

void NativeUtils::pushNotification(const char* content, int  time)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniHelpers::jniCommonVoidCall(
                                  "pushNotification",
                                  CLASS_NAME,
                                  content, time);
#endif
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //    PlayGameSingleton::sharedInstance().showSingleLeaderboard(leaderboardID);
#endif
}
