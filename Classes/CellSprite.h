#pragma once
#include "cocos2d.h"
USING_NS_CC;

enum enumCellSpriteStatus {
	ecssNormal,
	ecssMove
};

class CellSprite :
	public CCNode {
public:
	CellSprite();
	virtual ~CellSprite();
	virtual bool init();
	CREATE_FUNC(CellSprite);

	CCSprite * m_primarySprite;
	enumCellSpriteStatus m_status; // 当前状态;
	CCPoint m_curLoc; // 当前位置;
	CCPoint m_tarLoc; // 目标位置;
	void beganMove();
	void beganMove_over(CCNode * pSender);
	
	void runAction_normal();
	void runAction_normal_subFunc(float dt);
};
