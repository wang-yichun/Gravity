#pragma once
#include "cocos2d.h"
#include "MapCell.h"
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
	enumCellSpriteStatus m_status; // ��ǰ״̬;
	CCPoint m_curLoc; // ��ǰλ��;
	CCPoint m_tarLoc; // Ŀ��λ��;
	enumMapCellPollCode m_pollCode; // Ŀ����Ⱦ;

	void poll(); // ��Ⱦ;
	void move_random(); // ����ƶ�;

	void beganMove();
	void beganMove_over(CCNode * pSender);
	
	void runAction_normal();
	void runAction_normal_subFunc(float dt);
};
