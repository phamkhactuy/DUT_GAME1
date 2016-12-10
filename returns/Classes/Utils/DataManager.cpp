//
//  DataManager.cpp
//  gamebase
//
//  Created by keikan on 4/14/15.
//
//

#include "DataManager.h"
USING_NS_CC;

using namespace rapidjson;

DataManager* DataManager::_instance = NULL;

DataManager* DataManager::getInstance()
{
    if (!_instance) {
        _instance = new DataManager();
    }
    return _instance;
}

DataManager::DataManager()
{
//    loadLevelPositionData();
    loadGameSetting();
    loadLevelsCleared();
    loadGameInfo();
    loadInventory();
    loadAchievement();
    
    log("----%s", FileUtils::getInstance()->getWritablePath().c_str());
}
DataManager::~DataManager()
{
    
}

bool DataManager::writeToJsonFile(std::string filePath, rapidjson::Document &document)
{
//    // to Serialize to JSON String
    rapidjson::StringBuffer sb;
    rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
    document.Accept(writer);
    
    std::FILE *fwrite = fopen(filePath.c_str(), "w");
    if (!fwrite) {
        return false;
    }
    fprintf(fwrite, "%s",sb.GetString());
    fclose(fwrite);
    
    document.Parse<0>(sb.GetString());
    
    return true;
}


rapidjson::Document DataManager::loadMapData(int land)
{
    std::string dataPath = StringUtils::format("data/map_data_%d.json",land);
    std::string fullpath = "";
    ssize_t filesize;
    char* data;
    std::string content;
    fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
    content.append(data);
    content = content.substr(0, filesize);
    rapidjson::Document doc;
    doc.Parse<0>(content.c_str());
    return doc;
}

rapidjson::Document DataManager::loadLevelPositionData(int land)
{
    std::string dataPath = StringUtils::format("data/map_level_%d.json",land);
//    std::string dataPath = "data/map_level_1.json";
    std::string fullpath = "";
    ssize_t filesize;
    char* data;
    std::string content;
    fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
    content.append(data);
    content = content.substr(0, filesize);
//    _positionLevelDoc.Parse<0>(content.c_str());
    rapidjson::Document doc;
//    log("%s", content.c_str());
    doc.Parse<0>(content.c_str());
    return doc;
}

void DataManager::loadGameSetting()
{
    std::string dataPath = FileUtils::getInstance()->getWritablePath() + "setting.json";
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    
    if (FileUtils::getInstance()->isFileExist(fullpath))
    {
        ssize_t filesize;
        char* data;
        std::string content;
        data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
        content.append(data);
        content = content.substr(0, filesize);
        _gameSettingDoc.Parse<0>(content.c_str());
    }
    else
    {
        std::string sound = "sound";
        std::string control = "control";
        std::string music = "music";
        std::string difficult = "difficult";
        std::string max_level = "max_level";
        std::string current_level = "current_level";
        
        Document::AllocatorType& allocator = _gameSettingDoc.GetAllocator();
        
        _gameSettingDoc.SetObject();
//        _gameSettingDoc.AddMember(sound.c_str(),100,allocator);
//        _gameSettingDoc.AddMember(music.c_str(),100,allocator);
//        _gameSettingDoc.AddMember(difficult.c_str(),1,allocator);
//        _gameSettingDoc.AddMember(control.c_str(),1,allocator);
//        _gameSettingDoc.AddMember(max_level.c_str(),1,allocator);
//        _gameSettingDoc.AddMember(current_level.c_str(),1,allocator);
//        
        this->writeToJsonFile(fullpath, _gameSettingDoc);
    }
}

void DataManager::loadLevelsCleared()
{
    std::string dataPath = FileUtils::getInstance()->getWritablePath() + "levels_cleared.json";
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    
    if (FileUtils::getInstance()->isFileExist(fullpath))
    {
        ssize_t filesize;
        char* data;
        std::string content;
        data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
        content.append(data);
        content = content.substr(0, filesize);
        _levelsClearedDoc.Parse<0>(content.c_str());
    }
    else
    {
        _levelsClearedDoc.SetObject();
        this->writeToJsonFile(fullpath, _levelsClearedDoc);
    }
}


void DataManager::loadGameInfo()
{
    std::string dataPath = FileUtils::getInstance()->getWritablePath() + "game_info.json";
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    
    if (FileUtils::getInstance()->isFileExist(fullpath))
    {
        ssize_t filesize;
        char* data;
        std::string content;
        data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
        content.append(data);
        content = content.substr(0, filesize);
        _gameInfo.Parse<0>(content.c_str());
    }
    else
    {
        std::string first_activity = "first_activity";
        std::string last_activity = "last_activity";
        Document::AllocatorType& allocator = _gameInfo.GetAllocator();
        
        double activity1 = time(NULL);
        double activity2 = time(NULL);
        _gameInfo.SetObject();
//        _gameInfo.AddMember(first_activity.c_str(), activity1, allocator);
//        _gameInfo.AddMember(last_activity.c_str(), activity2, allocator);
        this->writeToJsonFile(fullpath, _gameInfo);
    }
}

void DataManager::loadInventory()
{
    std::string dataPath = FileUtils::getInstance()->getWritablePath() + "inventory.json";
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    
    if (FileUtils::getInstance()->isFileExist(fullpath))
    {
        ssize_t filesize;
        char* data;
        std::string content;
        data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
        content.append(data);
        content = content.substr(0, filesize);
        _inventory.Parse<0>(content.c_str());
    }
    else
    {
        std::string coins = "coins";
        std::string bombs = "bombs";
        std::string rockets = "rockets";
        std::string mines = "mines";
        std::string time_bombs = "time_bombs";
        std::string switch_bombs = "switch_bombs";
        std::string snow_flakes = "snow_flakes";
        
        Document::AllocatorType& allocator = _inventory.GetAllocator();
        
        _inventory.SetObject();
//        _inventory.AddMember(coins.c_str(),10000,allocator);
//        _inventory.AddMember(bombs.c_str(),100,allocator);
//        _inventory.AddMember(rockets.c_str(),100,allocator);
//        _inventory.AddMember(mines.c_str(),100,allocator);
//        _inventory.AddMember(time_bombs.c_str(),100,allocator);
//        _inventory.AddMember(snow_flakes.c_str(),100,allocator);
//        _inventory.AddMember(switch_bombs.c_str(),100,allocator);
//        
        this->writeToJsonFile(fullpath, _inventory);
    }
}

void DataManager::loadAchievement()
{
    std::string dataPath = FileUtils::getInstance()->getWritablePath() + "achievement.json";
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    
    if (FileUtils::getInstance()->isFileExist(fullpath))
    {
        ssize_t filesize;
        char* data;
        std::string content;
        data = (char*)FileUtils::getInstance()->getFileData(fullpath.c_str(), "r", &filesize);
        content.append(data);
        content = content.substr(0, filesize);
        _achievement.Parse<0>(content.c_str());
    }
    else
    {
        std::string total_activities = "total_activities";
        std::string share_facebook = "share_facebook";
        std::string share_twitter = "share_twitter";
        std::string diamonds = "diamonds";
        std::string enemies = "enemies";
        std::string coin_box = "coin_box";
        
        Document::AllocatorType& allocator = _achievement.GetAllocator();
        
        _achievement.SetObject();
//        _achievement.AddMember(total_activities.c_str(),1,allocator);
//        _achievement.AddMember(share_facebook.c_str(),0,allocator);
//        _achievement.AddMember(share_twitter.c_str(),0,allocator);
//        _achievement.AddMember(diamonds.c_str(),0,allocator);
//        _achievement.AddMember(enemies.c_str(),0,allocator);
//        _achievement.AddMember(coin_box.c_str(),0,allocator);
//        
        this->writeToJsonFile(fullpath, _achievement);
    }
}

MapData DataManager::getMapDataAtLevel(int land, int level)
{
    rapidjson::Document doc = this->loadMapData(land);
    
    rapidjson::Value &obj = doc[StringUtils::format("map%d",level).c_str()];
    
    int diamond = obj["diamond"].GetInt();
    int fuel = obj["fuel"].GetInt();
    int enemy = obj["enemy"].GetInt();
    int timeBomb = obj["timebomb"].GetInt();
    int bomb = obj["bomb"].GetInt();
    
    int rocket = obj["rocket"].GetInt();
    int mine = obj["mine"].GetInt();
    
    return MapData(diamond, fuel, enemy, 100, bomb, timeBomb, rocket, mine);
}

Inventory DataManager::getInventory()
{
    return Inventory(_inventory["bombs"].GetInt(),
                     _inventory["mines"].GetInt(),
                     _inventory["time_bombs"].GetInt(),
                     _inventory["rockets"].GetInt(),
                     _inventory["coins"].GetInt(),
                     _inventory["snow_flakes"].GetInt(),
                     _inventory["switch_bombs"].GetInt());
}

std::vector<cocos2d::Vec2> DataManager::getPositionAtLevel(int land)
{
    rapidjson::Document doc = loadLevelPositionData(land);
    rapidjson::Value& obj = doc["points1"];
    int size = obj.Size();
    
    std::vector<Vec2> arr;
    
    for (int i = 0; i < size; i++) {
        arr.push_back(cocos2d::Vec2(obj[i]["x"].GetInt(),obj[i]["y"].GetInt()));
    }
    
    return arr;
}

void DataManager::saveGameSetting()
{
    std::string dataPath = FileUtils::getInstance()->getWritablePath() + "setting.json";
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(dataPath);
    this->writeToJsonFile(fullpath, _gameSettingDoc);
}
