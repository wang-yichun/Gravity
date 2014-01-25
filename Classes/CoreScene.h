#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

//	������	BgLayer		100		kBgLayer
//	��ɫ��	RoleLayer	200		kRoleLayer
//	��Ч��	GfxLayer	300		kGfxLayer
enum TCoreScene {
	kBgLayer = 0,
	kRoleLayer,
	kGfxLayer
};

class CoreScene :
	public CCScene {
public:
	CoreScene(void);
	virtual ~CoreScene(void);
	virtual bool init();
	CREATE_FUNC(CoreScene);

	void step(float dt);

	void startStage();
	UIWidget * uiWidget;
};

