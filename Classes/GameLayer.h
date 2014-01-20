#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Stage.h"
#include "SystemManager.h"
#include "GameManager.h"
USING_NS_CC;
USING_NS_CC_EXT;

//////////////////////////////////////////////////////////////////////////
// 真正游戏内大小的Layer;
//////////////////////////////////////////////////////////////////////////
class GameLayer :
	public CCLayerColor
{
public:
	GameLayer();
	virtual ~GameLayer();
	CREATE_FUNC(GameLayer);
	bool init();

	// default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);

private:

};
