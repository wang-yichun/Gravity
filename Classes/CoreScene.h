#pragma once
#include "cocos2d.h"
USING_NS_CC;

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
};

