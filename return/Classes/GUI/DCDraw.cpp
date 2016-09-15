//
//  DCDraw.cpp
//  gamebase
//
//  Created by NGOCDIEP on 5/4/15.
//
//

#include "DCDraw.h"

//Class DCDrawCircle
DCDrawCircle::DCDrawCircle(const Vec2& postion,Color4B color, int lineWidth, float radius, float angle, unsigned int segments, bool drawLineToCenter, bool solid){
    this->postion = postion;
    this->color = color;
    this->lineWidth = lineWidth;
    this->radius = radius;
    this->angle = angle;
    this->segments = segments;
    this->drawLineToCenter = drawLineToCenter;
    this->solid = solid;
}
DCDrawCircle::~DCDrawCircle(){
    //end draw
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
void DCDrawCircle::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(DCDrawCircle::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}
void DCDrawCircle::onDraw(const cocos2d::Mat4 &transform, uint32_t flags){
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    
    glLineWidth(lineWidth);
    DrawPrimitives::setDrawColor4B(this->color.r,this->color.g,this->color.b,this->color.a);
    if(solid){
        DrawPrimitives::drawSolidCircle(this->postion, this->radius, this->angle, this->segments, 1.0f, 1.0f);
    }else{
        DrawPrimitives::drawCircle( this->postion, this->radius, this->angle, this->segments, this->drawLineToCenter);
    }
}
/**Using
 // draw a green circle with 10 segments
 DrawPrimitives::drawCircle( VisibleRect::center(), 100, 0, 10, false);
 
 // draw a green circle with 50 segments with line to center
 DrawPrimitives::drawCircle( VisibleRect::center(), 50, CC_DEGREES_TO_RADIANS(90), 50, true);
 
 // draw a pink solid circle with 50 segments
 DCDrawCircle *dr = new DCDrawCircle(VisibleRect::center(), Color4B::BLUE,0, 40, CC_DEGREES_TO_RADIANS(90), 50, false, true);
 */
//-------------------


//Class DCDrawPoly
DCDrawPoly::DCDrawPoly( Color4B color,int lineWidth,int numberOfPoints, Vec2 vertices[100], bool closePolygon, bool solid){
//    this->postion = postion;
    this->color = color;
    this->lineWidth = lineWidth;
    this->numberOfPoints = numberOfPoints;
    //    this->vertices = vertices;
    for(int i = 0; i < 100; i++){
        if(i< this->numberOfPoints)
            this->vertices[i] = vertices[i];
        else
            this->vertices[i] = Vec2(0,0);
    }
    this->closePolygon = closePolygon;
    this->solid = solid;
    
}
DCDrawPoly::~DCDrawPoly(){
    //end draw
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
void DCDrawPoly::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(DCDrawPoly::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}
void DCDrawPoly::onDraw(const cocos2d::Mat4 &transform, uint32_t flags){
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    
    glLineWidth(this->lineWidth);
    if(this->solid){
        //filled poly
        DrawPrimitives::drawSolidPoly(vertices, this->numberOfPoints, Color4F(this->color));
    }else{
        DrawPrimitives::setDrawColor4B(this->color.r,this->color.g,this->color.b,this->color.a);
        DrawPrimitives::drawPoly( vertices, 5, this->closePolygon);
    }
    
}
/**Using
 // filled poly
 Vec2 filledVertices[] = { Vec2(0,120), Vec2(50,120), Vec2(50,170), Vec2(25,200), Vec2(0,170) };
 DCDrawPoly *dr = new DCDrawPoly(Color4B::GREEN, 1, 5, filledVertices, false,true);
 dr->setPosition(VisibleRect::center());
 
 // open poly
 Vec2 filledVertices[] = { Vec2(0,120), Vec2(50,120), Vec2(50,170), Vec2(25,200), Vec2(0,170) };
 DCDrawPoly *dr = new DCDrawPoly(Color4B::GREEN, 1, 5, filledVertices, false,false);
 dr->setPosition(VisibleRect::center());
 
 // close poly
 Vec2 filledVertices[] = { Vec2(0,120), Vec2(50,120), Vec2(50,170), Vec2(25,200), Vec2(0,170) };
 DCDrawPoly *dr = new DCDrawPoly(Color4B::GREEN, 1, 5, filledVertices, true,false);
 dr->setPosition(VisibleRect::center());
 */
//-------------------




//Class DCDrawLine
DCDrawLine::DCDrawLine( Color4B color,int lineWidth,Vec2 posStart, Vec2 posEnd){
    //    this->postion = postion;
    this->color = color;
    this->lineWidth = lineWidth;
    this->posStart = posStart;
    this->posEnd = posEnd;
    
}
DCDrawLine::~DCDrawLine(){
    //end draw
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}
void DCDrawLine::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags){
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(DCDrawLine::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}
void DCDrawLine::onDraw(const cocos2d::Mat4 &transform, uint32_t flags){
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);
    
    glLineWidth(this->lineWidth);
    DrawPrimitives::setDrawColor4B(this->color.r,this->color.g,this->color.b,this->color.a);
    DrawPrimitives::drawLine(posStart, posEnd);
    
}
/**Using
    DCDrawLine *dr = new DCDrawLine(Color4B::GRAY, 10, VisibleRect::rightBottom(), VisibleRect::leftTop());
 */
//-------------------
