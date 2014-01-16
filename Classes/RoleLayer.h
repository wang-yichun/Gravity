#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

enum TRoleLayer {
	kDebugLabel,
	kShip,
	kDownControl
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

	// step
	void step(float dt);

	// ship propties.
	CCPoint a;
	CCPoint v;

	CCPoint ai[3];

	// control
	void left_power_on(CCObject* pSender, CCControlEvent event);  
	void left_power_off(CCObject* pSender, CCControlEvent event);  

	void down_power_on(CCObject* pSender, CCControlEvent event);  
	void down_power_off(CCObject* pSender, CCControlEvent event);

	void right_power_on(CCObject* pSender, CCControlEvent event);  
	void right_power_off(CCObject* pSender, CCControlEvent event);  
};