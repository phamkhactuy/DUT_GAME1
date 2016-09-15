//
//  TileMap.h
//  bomberman
//
//  Created by NGOCDIEP on 3/5/15.
//
//

#ifndef __bomberman__TileMap__
#define __bomberman__TileMap__

#include "cocos2d.h"
#include "LayerDisplay.h"


class TileMap : public LayerDisplay{
public:
    
    static TileMap * getInstance(void);
    
    TileMap();
    virtual ~TileMap();
    
    static TileMap* create(int level);
    
    virtual bool init(int level);

    
    void removeTileInMap(cocos2d::TMXLayer* layer, cocos2d::Vec2 pos);
    bool checkPathPlayer(cocos2d::Vec2 pos);
    int getIdTile(cocos2d::TMXLayer* layer, cocos2d::Vec2 pos);
    void setIdTile(cocos2d::TMXLayer* layer,cocos2d::Vec2 pos, int id);
    
    void onTouchesBegan (const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
    void onTouchesEnded (const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event);
    
    
private:
    void addItem();
    void initObject();
    bool checkPos(cocos2d::Vec2 pos);
    void setFunTile(cocos2d::Vec2 pos);
    void removeTile(cocos2d::Vec2 pos);
    
    void initCave(int i, int j, int id);
    
    CC_SYNTHESIZE(cocos2d::TMXTiledMap*, _tileMap, TileMap);
    CC_SYNTHESIZE(cocos2d::TMXLayer*, _layerItems, LayerItems);
    CC_SYNTHESIZE(cocos2d::TMXLayer*, _layerBackground, LayerBackground);
    CC_SYNTHESIZE(cocos2d::Size, _tileSize, TileSize);
    CC_SYNTHESIZE(cocos2d::Size, _tileMapSize, TileMapSize);
    CC_SYNTHESIZE(cocos2d::Size, _tileMapSizeMatrix, TileMapSizeMatrix);
    CC_SYNTHESIZE(cocos2d::Size, _posPlayer, PosPlayer);
    CC_SYNTHESIZE(cocos2d::Vec2, _startPos, StartPos);
    CC_SYNTHESIZE(cocos2d::Size, _endPos, EndPos);
    CC_SYNTHESIZE(cocos2d::Vec2, _dirPath, DirPath);
    
    CC_SYNTHESIZE(int, _totalKey, TotalKey);
    CC_SYNTHESIZE(int, _totalLeft, TotalLeft);
    CC_SYNTHESIZE(int, _totalRight, TotalRight);
    CC_SYNTHESIZE(int, _totalTop, TotalTop);
    CC_SYNTHESIZE(int, _totalBot, TotalBot);
    CC_SYNTHESIZE(int, _totalSprings, TotalSprings);
    CC_SYNTHESIZE(int, _totalStar, TotalStar);
    CC_SYNTHESIZE(int, _currenKey, CurrenKey);
    CC_SYNTHESIZE(int, _currenStar, CurrenStar);
    
    CC_SYNTHESIZE(cocos2d::Vec4, _cave_1, Cave_1);
    CC_SYNTHESIZE(cocos2d::Vec4, _cave_2, Cave_2);
    CC_SYNTHESIZE(cocos2d::Vec4, _cave_3, Cave_3);
    CC_SYNTHESIZE(cocos2d::Vec4, _cave_4, Cave_4);
};
#endif /* defined(__bomberman__TileMap__) */
