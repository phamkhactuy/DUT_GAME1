//
//  Player.cpp
//  game1
//
//  Created by NGOCDIEP on 11/4/15.
//
//

#include "Player.h"
#include "MainGameScene.h"
#include "VisibleRect.h"
#include "ConvertUtils.h"
#include "TileMap.h"
#include "Constants.h"
#include "SkillLayer.h"
#include "CompleteGame.h"

USING_NS_CC;

#define SPEED_LOOP 5
#define DELTA_MOVE Vec2(1,1)

#define FRAME_IDLE 2
#define FRAME_RUN 2
#define FRAME_JUMP 2
#define FRAME_DIE 1

#define ID_CHAR "Player"


Player::Player(){
    
    this->setFrDie(FRAME_DIE);
    this->setFrRun(FRAME_RUN);
    this->setFrJump(FRAME_JUMP);
    this->setFrIdle(FRAME_IDLE);
    
    this->setIdChar(ID_CHAR);
    this->setDeltaMove(DELTA_MOVE);
    this->setDirChar(dirRight);
    this->setFrameChar(1);
    this->setStateChar(stateIdle);
    this->setLevelChar(1);
    
    _flagCave = 0;
    
    std::string key = cocos2d::StringUtils::format("%s_%d_%d_%d_%d.png", ID_CHAR, this->getLevelChar(), this->getDirChar(), this->getStateChar(), this->getFrameChar());
    
    this->getSpriteChar()->setSpriteFrame(key);
    
    _posOrigin = VisibleRect::center() - Vec2(TileMap::getInstance()->getTileMap()->getContentSize().width * 0.5, TileMap::getInstance()->getTileMap()->getContentSize().height * 0.5);
}

Player::~Player(){
    
}

void Player::setPositionMap(Vec2 pos){
    //Đảo chiều y do hệ toạ độ tilemap khác hệ toạ độ cocos2dx.
    Vec2 posPlayer = Vec2(pos.x * TileMap::getInstance()->getTileSize().width,  fabs(TileMap::getInstance()->getTileMap()->getContentSize().height - pos.y * TileMap::getInstance()->getTileSize().height));
    posPlayer  +=  Vec2(TILE_SIZE * 0.5, -TILE_SIZE * 0.5);
    this->getSpriteChar()->setPosition(posPlayer);
    
    
}

void Player::update(int loop){
    
    if(loop % SPEED_LOOP == 0){
        this->doUpdateFrame(loop);
    }
    
    if(_flagCave != 0 && loop - _flagCave > 50){
        _flagCave = 0;
    }
    
    Vec2 posMap = this->getSpriteChar()->getPosition();

    this->doUpdatePos();
    
    //xu ly logic game
    logic(posMap, loop);
    
}

void Player::logic(Vec2 posMap, int loop){
    //Thiết lập vị trí xác nhận va chạm cho đối tượng
    switch (this->getDirChar()) {
        case dirRight:
            posMap += Vec2(-TILE_SIZE * 0.5, 0);
            break;
        case dirLeft:
            posMap += Vec2(TILE_SIZE * 0.5, 0);
            break;
        case dirTop:
            posMap += Vec2(0, -TILE_SIZE * 0.5);
            break;
        case dirBot:
            posMap += Vec2(0, TILE_SIZE * 0.5);
            break;
        default:
            break;
    }
    
    Vec2 posMatrix = ConvertUtils::convertCDMaptoMatrix(posMap, TileMap::getInstance()->getTileSize(), TileMap::getInstance()->getTileMapSizeMatrix());
    int idTile = TileMap::getInstance()->getIdTile(TileMap::getInstance()->getLayerItems(), posMatrix);
    switch (idTile) {
        case TILE_LEFT:
            this->setDirChar(dirLeft);
            break;
        case TILE_RIGHT:
            this->setDirChar(dirRight);
            break;
        case TILE_TOP:
            this->setDirChar(dirTop);
            break;
        case TILE_BOT:
            this->setDirChar(dirBot);
            break;
        case TILE_BARRIER://Gặp item nay sẽ đi quay lại
            if(this->getDirChar() == dirLeft)
                this->setDirChar(dirRight);
            else if(this->getDirChar() == dirRight)
                this->setDirChar(dirLeft);
            else if(this->getDirChar() == dirTop)
                this->setDirChar(dirBot);
            else if(this->getDirChar() == dirBot)
                this->setDirChar(dirTop);
    
            break;
        case TILE_ITEM_1:
            moveOneStep(posMatrix);
            break;
        case TILE_CAVE_1:
            moveCave(TILE_CAVE_1, posMatrix, loop);
            break;
        case TILE_CAVE_2:
            moveCave(TILE_CAVE_2, posMatrix, loop);
            break;
        case TILE_CAVE_3:
            moveCave(TILE_CAVE_3, posMatrix, loop);
            break;
        case TILE_CAVE_4:
            moveCave(TILE_CAVE_4, posMatrix, loop);
            break;
        case TILE_STAR:
            TileMap::getInstance()->removeTileInMap(TileMap::getInstance()->getLayerItems(), posMatrix);
            TileMap::getInstance()->setCurrenStar(TileMap::getInstance()->getCurrenStar() + 1);
            SkillLayer::getInstance()->updateFun();
            break;
            
        case TILE_KEY:
            TileMap::getInstance()->removeTileInMap(TileMap::getInstance()->getLayerItems(), posMatrix);
            TileMap::getInstance()->setCurrenKey(TileMap::getInstance()->getCurrenKey() + 1);
            SkillLayer::getInstance()->updateFun();
            break;
        case TILE_DEFAULT:
            //Trường hợp đi vào 4 biên.
            if(posMatrix.x == 0 && this->getDirChar() == dirLeft){
                this->setDirChar(dirRight);
            }
            if(posMatrix.x == TileMap::getInstance()->getTileMapSizeMatrix().width - 1 && this->getDirChar() == dirRight){
                this->setDirChar(dirLeft);
            }
            if(posMatrix.y == 0 && this->getDirChar() == dirTop){
                this->setDirChar(dirBot);
            }
            if(posMatrix.y == TileMap::getInstance()->getTileMapSizeMatrix().height - 1 && this->getDirChar() == dirBot){
                this->setDirChar(dirTop);
            }
            break;
        case TILE_END:
            gameWin();
            break;

    }
}

void Player::gameWin(){
    this->setStateChar(stateDie);
    auto sence = CompleteGame::createScene();
    Director::getInstance()->replaceScene(sence);
}

void Player::moveOneStep(Vec2 posMatrix){
    switch (this->getDirChar()) {
        case dirLeft:
            MainGameScene::getInstance()->getMainChar()->setPositionMap(posMatrix + Vec2(-2, 0));
            break;
        case dirRight:
            MainGameScene::getInstance()->getMainChar()->setPositionMap(posMatrix + Vec2(2, 0));
            break;
        case dirTop:
            MainGameScene::getInstance()->getMainChar()->setPositionMap(posMatrix + Vec2(0, -2));
            break;
        case dirBot:
            MainGameScene::getInstance()->getMainChar()->setPositionMap(posMatrix + Vec2(0, 2));
            break;
        default:
            break;
    }
    
}

void Player::moveCave(int idTile, Vec2 posMatrix, int loop){
    if(_flagCave == 0){
        if(posMatrix.x == TileMap::getInstance()->getCave_1().x && posMatrix.y == TileMap::getInstance()->getCave_1().y){
            MainGameScene::getInstance()->getMainChar()->setPositionMap(Vec2(TileMap::getInstance()->getCave_1().z,TileMap::getInstance()->getCave_1().w));
        }else{
            MainGameScene::getInstance()->getMainChar()->setPositionMap(Vec2(TileMap::getInstance()->getCave_1().x,TileMap::getInstance()->getCave_1().y));
        }
        _flagCave = loop;
    }
    
}






