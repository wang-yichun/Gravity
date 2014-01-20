#pragma once
#include "cocos2d.h"
#include "CellSprite.h"
#include "GameManager.h"
USING_NS_CC;

enum enumDirectSelectStatus {
	edssNormal,
	edssSuccess,
	edssFailed,
	edssCanceled
};

class GameManager {
private:
	GameManager();
	virtual ~GameManager();
	static GameManager * s_GameManager;
	bool init();

public:
	CCArray * m_cellSprites;

	static GameManager * GetInstance();
	void prepareStage(); // ׼����Ϸ;
	void stepStage(); // ��Ϸ������һ������;
	void stepCellSprites(CellSprite * cell_node);

	void insertSpriteToStage(CCPoint loc);
};
