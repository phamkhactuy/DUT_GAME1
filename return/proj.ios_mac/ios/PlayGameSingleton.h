//
//  ControllerSingleLeaderboard.h
//  GooglePlayGameServices
//
//  Created by NSS on 4/7/14.
//
//

#ifndef __PLAY_GAME_SINGLETON_H__
#define __PLAY_GAME_SINGLETON_H__


class PlayGameSingleton {
public:
    static PlayGameSingleton& sharedInstance();
    ~PlayGameSingleton();
    PlayGameSingleton();
    
    void showSingleLeaderboard(const char* leaderBoardID);
    void finishSingleLeaderboard();
    
    void showLeaderboards();
    void finishLeaderboards();
    
    void submitScore(long score, const char* leaderBoardID);
    
    void showAchievements();
    void finishAchievements();
    
    void revealAchievement(const char* achievementID);
    void unlockAchievement(const char* achievementID);
    void incrementAchievement(int numSteps, const char* achievementID);
    void incrementPercentageAchievement(float percentage, const char* achievementID);
    
    void authenticate();
    void signOut();
    void trySilentAuthentication();
    bool isSignedIn();
    
    void initAd();
    void showAd();
    void hideAd();
    
    void rateApp();
    
    void shareOnFacebook(long score, int level, int obstacles);
    void shareOnFacebook(char* msg, char* url, char* image);
    void shareOnTwitter(char* msg, char* url, char* image);
private:
    void* rootController;
};

#endif
