#pragma once
#include "cocos2d.h"
USING_NS_CC;

//	±³¾°²ã	BgLayer		100		kBgLayer
//	½ÇÉ«²ã	RoleLayer	200		kRoleLayer
//	ÌØÐ§²ã	GfxLayer	300		kGfxLayer
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

