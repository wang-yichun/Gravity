#pragma once
#include "cocos2d.h"
#include "sqlite_header.h"
USING_NS_CC;

class TestScene : 
	public CCScene
{
public:
	TestScene(void);
	virtual ~TestScene(void);
	virtual bool init();

	CREATE_FUNC(TestScene);

	CCLayer* m_layer01;
	CCLayerColor* m_colorLayer;

	void menuCallback(CCObject* sender);
	void SampleSelectorWithData(CCNode *sender, void *data);
};

