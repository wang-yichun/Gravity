#pragma once
#include "cocos2d.h"
USING_NS_CC;

enum TRoleLayer {
	kDebugLabel
};

class RoleLayer :
	public CCLayer
{
public:
	RoleLayer();
	virtual ~RoleLayer();
	virtual bool init();
	CREATE_FUNC(RoleLayer);

	// default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
};