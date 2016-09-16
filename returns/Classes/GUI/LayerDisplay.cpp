//
//  LayerDisplay.cpp
//  gamebase
//
//  Created by NgocDiep on 5/12/15.
//
//

#include "LayerDisplay.h"
#include "VisibleRect.h"
USING_NS_CC;

/**
 * super
 */
LayerDisplay::LayerDisplay()
{
    m_pWindow = cocos2d::cocoswidget::CWidgetWindow::create();
}

LayerDisplay::~LayerDisplay()
{
}

void LayerDisplay::setShow(bool show, int flag){
    this->setVisible(show);
}

void LayerDisplay::setPos(Vec2 pos, int flag){
    this->setPos(pos);
}