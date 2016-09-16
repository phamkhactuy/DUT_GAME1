//
//  DCDraw.h
//  gamebase
//
//  Created by NGOCDIEP on 5/4/15.
//
//

#ifndef __gamebase__DCDraw__
#define __gamebase__DCDraw__

#include <stdio.h>
#include <cocos2d.h>
USING_NS_CC;
class DCDrawCircle : public cocos2d::Layer{
public:
    DCDrawCircle(const Vec2& postion, Color4B color,int lineWidth, float radius, float angle, unsigned int segments, bool drawLineToCenter, bool solid = false);
    ~DCDrawCircle();
    
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
private:
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
    cocos2d::CustomCommand _customCommand;
    
    Vec2 postion;//Vi tri
    Color4B color;//Mau sac
    int lineWidth;//Do rong cua duong tron
    float radius;//ban kinh
    float angle;//goc
    unsigned int segments;//phan doan
    bool drawLineToCenter;//duong nam ngang
    bool solid;
};

class DCDrawPoly : public Layer{
public:
    DCDrawPoly(Color4B color,int lineWidth,int numberOfPoints, Vec2 vertices[100], bool closePolygon, bool solid = false);
    ~DCDrawPoly();
    
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
//    Vec2 postion;//Vi tri
    Color4B color;//Mau sac
    int lineWidth;//Do rong cua duong tron
    bool solid;
    int numberOfPoints;
    Vec2 vertices[100];
    bool closePolygon;

private:
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
    cocos2d::CustomCommand _customCommand;

};

class DCDrawLine : public Layer{
public:
    DCDrawLine(Color4B color,int lineWidth,Vec2 posStart, Vec2 posEnd);
    ~DCDrawLine();
    
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
    //    Vec2 postion;//Vi tri
    Color4B color;//Mau sac
    int lineWidth;//Do rong cua duong tron
    Vec2 posStart;
    Vec2 posEnd;
    
private:
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
    cocos2d::CustomCommand _customCommand;
};
#endif /* defined(__gamebase__DCDraw__) */
