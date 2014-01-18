#pragma once
#include "cocos2d.h"
USING_NS_CC;

class CellSprite :
	public CCNode {
public:
	CellSprite();
	virtual ~CellSprite();
	virtual bool init();
	CREATE_FUNC(CellSprite);

	CCSprite * m_primarySprite;
	
	void runAction_normal();
};
