#pragma once
#include "cocos2d.h"
USING_NS_CC;

class GameManager {

private:
	GameManager();
	virtual ~GameManager();
	static GameManager * s_GameManager;
	bool init();
public:
	static GameManager * GetInstance();
};
