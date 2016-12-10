//
//  TileMap.cpp
//  bomberman
//
//  Created by NGOCDIEP on 3/5/15.
//
//

#include "TileMap.h"
#include "MainGameScene.h"
#include "PointInTriangle.h"
#include "VisibleRect.h"
#include "Constants.h"
#include "ConvertUtils.h"
#include "SkillLayer.h"

USING_NS_CC;
using namespace std;

static TileMap *s_SharedGameUtils = NULL;

TileMap* TileMap::getInstance(void)
{
    return s_SharedGameUtils;
}

TileMap::TileMap()
{
    _totalKey = 0;
    _totalLeft = 0;
    _totalRight = 0;
    _totalTop = 0;
    _totalBot = 0;
    _totalSprings = 0;
    _totalStar = 0;
    _currenKey = 0;
    _currenStar = 0;
    _cave_1 = Vec4(-1,-1,-1,-1);
    _cave_2 = Vec4(-1,-1,-1,-1);
    _cave_3 = Vec4(-1,-1,-1,-1);
    _cave_4 = Vec4(-1,-1,-1,-1);
    
}

TileMap::~TileMap()
{
    _tileMap = NULL;
    _layerBackground = NULL;
    _layerItems = NULL;
}

TileMap* TileMap::create(int level)
{
    TileMap* pRet = new TileMap();
    if( pRet && pRet->init(level) )
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

bool TileMap::init(int level){
    
    s_SharedGameUtils = this;
    
    if(level < 0)
        return false;
    
    _tileMap = TMXTiledMap::create(StringUtils::format("res/Maps/level%d.tmx",level));
    _layerBackground = _tileMap->getLayer("background");
    _layerItems = _tileMap->getLayer("items");
    
    _tileSize = _tileMap->getTileSize();
    _tileMapSizeMatrix = _tileMap->getMapSize();
    _tileMapSize = Size(_tileMap->getMapSize().width * _tileSize.width,
                        _tileMap->getMapSize().height * _tileSize.height);
    
    _tileMap->setAnchorPoint(Vec2(0.5,0.5));
//    _tileMap->setScale(0.6);
    _tileMap->setPosition(VisibleRect::center());
    this->addChild(_tileMap,-1);
    
    addItem();
    initObject();
    
    return true;
}

void TileMap::addItem(){
    // Enable touches
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesBegan = CC_CALLBACK_2(TileMap::onTouchesBegan, this);
    touchListener->onTouchesMoved = CC_CALLBACK_2(TileMap::onTouchesMoved, this);
    touchListener->onTouchesEnded = CC_CALLBACK_2(TileMap::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener,this);
}
bool TileMap::checkPos(cocos2d::Vec2 pos){
    
    if(pos.x > VisibleRect::center().x - _tileMap->getContentSize().width * 0.5
       && pos.x < VisibleRect::center().x + _tileMap->getContentSize().width * 0.5
       && pos.y > VisibleRect::center().y - _tileMap->getContentSize().height * 0.5
       && pos.y < VisibleRect::center().y + _tileMap->getContentSize().height * 0.5){
        return true;
    }
    return false;
}
void TileMap::initObject()
{
    
    for (int i = 0; i < _tileMapSizeMatrix.width; i++)
    {
        for (int j = 0; j < _tileMapSizeMatrix.height; j++)
        {
            int id = this->getIdTile(_layerItems,Vec2(i,j));
            bool check = false;
            
            if (id == IDTILE::TILE_START){
                _startPos = Vec2(i,j);
                if(_startPos.x == 0){
                    //Huong di chuyen khi star la sang ben phai
                    _dirPath = Vec2(1,0);
                }
            }else if(id == IDTILE::TILE_CAVE_1 || id == IDTILE::TILE_CAVE_2 || id == IDTILE::TILE_CAVE_3 || id == IDTILE::TILE_CAVE_4){
                initCave(i, j, id);
            }else if (id == IDTILE::TILE_END){
                _endPos = Vec2(i,j);
            }else if(id == IDTILE::TILE_LEFT){
                check = true;
                _totalLeft++;
            }else if(id == IDTILE::TILE_RIGHT){
                check = true;
                _totalRight++;
            }else if(id == IDTILE::TILE_BOT){
                check = true;
                _totalBot++;
            }else if(id == IDTILE::TILE_TOP){
                check = true;
                _totalTop++;
            }else if(id == IDTILE::TILE_SPRINGS){
                check = true;
                _totalSprings++;
            }else if(id == IDTILE::TILE_STAR){
                _totalStar++;
            }else if(id == IDTILE::TILE_KEY){
                _totalKey++;
            }
            
            if(check){
                this->setIdTile(_layerItems, Vec2(i,j), IDTILE::TILE_DEFAULT);
            }
        }
    }
}
	
void TileMap::onTouchesBegan (const vector<Touch *> &touches, Event *event)
{
    Point p = touches[0]->getLocationInView();
    p = Director::getInstance()->convertToGL(p);
    bool ok = checkPos(p);
    if(ok == true){
        Vec2 tg = p - Vec2(VisibleRect::center().x - _tileMapSize.width * 0.5 ,VisibleRect::center().y - _tileMapSize.height * 0.5);
        Vec2 pos = ConvertUtils::convertCDMaptoMatrix(tg, _tileSize, _tileMapSizeMatrix);
        setFunTile(pos);
    }
    
}
void TileMap::setFunTile(Vec2 pos){
    switch (SkillLayer::getInstance()->getDir()) {
        case IDTILE::TILE_LEFT:{
            if(_totalLeft > 0 && this->getIdTile(_layerItems, pos) == IDTILE::TILE_DEFAULT){
                this->setIdTile(_layerItems, pos, IDTILE::TILE_LEFT);
                _totalLeft--;
                SkillLayer::getInstance()->updateFun();
            }
            break;
        }
        case IDTILE::TILE_RIGHT:{
            if(_totalRight > 0 && this->getIdTile(_layerItems, pos) == IDTILE::TILE_DEFAULT){
                this->setIdTile(_layerItems, pos, IDTILE::TILE_RIGHT);
                _totalRight--;
                SkillLayer::getInstance()->updateFun();
            }
            break;
        }
        case IDTILE::TILE_TOP:{
            if(_totalTop > 0 && this->getIdTile(_layerItems, pos) == IDTILE::TILE_DEFAULT){
                this->setIdTile(_layerItems, pos, IDTILE::TILE_TOP);
                _totalTop--;
                SkillLayer::getInstance()->updateFun();
            }
            break;
        }
        case IDTILE::TILE_BOT:{
            if(_totalBot > 0 && this->getIdTile(_layerItems, pos) == IDTILE::TILE_DEFAULT){
                this->setIdTile(_layerItems, pos, IDTILE::TILE_BOT);
                _totalBot--;
                SkillLayer::getInstance()->updateFun();
            }
            break;
        }
        case IDTILE::TILE_SPRINGS:{
            if(_totalSprings > 0 && this->getIdTile(_layerItems, pos) == IDTILE::TILE_DEFAULT){
                this->setIdTile(_layerItems, pos, IDTILE::TILE_SPRINGS);
                _totalSprings--;
                SkillLayer::getInstance()->updateFun();
            }
            break;
        }
        case IDTILE::TILE_REMOVE:{
            removeTile(pos);
            break;
        }
        default:
            break;
    }
}

void TileMap::removeTile(cocos2d::Vec2 pos){
    int id = this->getIdTile(_layerItems, pos);

    switch (id) {
        case IDTILE::TILE_LEFT:
            this->setIdTile(_layerItems, pos, IDTILE::TILE_DEFAULT);
            _totalLeft++;
            SkillLayer::getInstance()->updateFun();
            break;
        case IDTILE::TILE_RIGHT:
            this->setIdTile(_layerItems, pos, IDTILE::TILE_DEFAULT);
            _totalRight++;
            SkillLayer::getInstance()->updateFun();
            break;
        case IDTILE::TILE_TOP:
            this->setIdTile(_layerItems, pos, IDTILE::TILE_DEFAULT);
            _totalTop++;
            SkillLayer::getInstance()->updateFun();
            break;
        case IDTILE::TILE_BOT:
            this->setIdTile(_layerItems, pos, IDTILE::TILE_DEFAULT);
            _totalBot++;
            SkillLayer::getInstance()->updateFun();
            break;
        case IDTILE::TILE_SPRINGS:
            this->setIdTile(_layerItems, pos, IDTILE::TILE_DEFAULT);
            _totalSprings++;
            SkillLayer::getInstance()->updateFun();
            break;
    }
}

void TileMap::onTouchesEnded (const std::vector<Touch *> &touches, Event *event)
{
    
    
}
void TileMap::removeTileInMap(TMXLayer* layer , cocos2d::Vec2 pos)
{
    if(pos.x >= 0 && pos.y >= 0 && pos.x < _tileMapSizeMatrix.width && pos.y < _tileMapSizeMatrix.height){
        layer->removeTileAt(pos);
    }
}
bool TileMap::checkPathPlayer(cocos2d::Vec2 pos)
{
    return false;
}
int TileMap::getIdTile(cocos2d::TMXLayer* layer, cocos2d::Vec2 pos){
    
    if(pos.x >= 0 && pos.y >= 0 && pos.x < _tileMapSizeMatrix.width && pos.y < _tileMapSizeMatrix.height){
        return layer->getTileGIDAt(pos);
    }
    
    return -1;
}
void TileMap::setIdTile(cocos2d::TMXLayer* layer, cocos2d::Vec2 pos, int id)
{
    layer->setTileGID(id, pos);
}


void TileMap::initCave(int i, int j, int id){
    //Tao hang thông giữa hai vị trí. Hiện tại 1 map chỉ có thể thống giữa hai vị trí cho nhau
    if(id == IDTILE::TILE_CAVE_1){
        if(_cave_1.x == -1){
            _cave_1.x = i;
            _cave_1.y = j;
        }else{
            _cave_1.z = i;
            _cave_1.w = j;
        }
    }else if(id == IDTILE::TILE_CAVE_2){
        if(_cave_1.x == -1){
            _cave_1.x = i;
            _cave_1.y = j;
        }else{
            _cave_1.z = i;
            _cave_1.w = j;
        }
    }else if(id == IDTILE::TILE_CAVE_3){
        if(_cave_1.x == -1){
            _cave_1.x = i;
            _cave_1.y = j;
        }else{
            _cave_1.z = i;
            _cave_1.w = j;
        }
    }else if(id == IDTILE::TILE_CAVE_4){
        if(_cave_1.x == -1){
            _cave_1.x = i;
            _cave_1.y = j;
        }else{
            _cave_1.z = i;
            _cave_1.w = j;
        }
    }
}
