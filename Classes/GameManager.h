#pragma once
#include "cocos2d.h"
#include "CellSprite.h"
USING_NS_CC;

class GameManager {
private:
	GameManager();
	virtual ~GameManager();
	static GameManager * s_GameManager;
	bool init();

public:
	CCArray * m_cellSprites;

	static GameManager * GetInstance();
	void prepareStage(); // 准备游戏;
	void stepStage(); // 游戏进行下一步计算;
	void stepCellSprites(CellSprite * cell_node);
};
