#include "GameManager.h"
#include "Stage.h"

GameManager * GameManager::s_GameManager = NULL;

GameManager::GameManager():
	m_cellSprites(NULL){
}

GameManager::~GameManager() {
}

bool GameManager::init() {
	m_cellSprites = CCArray::create();
	m_cellSprites -> retain();
	return true;
}

GameManager * GameManager::GetInstance() {
	if (s_GameManager == NULL) {
		s_GameManager = new GameManager();
		s_GameManager -> init();
	}
	return s_GameManager;
}

void GameManager::prepareStage() {
	// 1. 在舞台增加几个cellsprite;
	for (int i = 0; i < 10; i++) {
		insertSpriteToStage(ccp(0,i));
	}
}

void GameManager::stepStage() {
	CCObject * cell_sprite;
	CCARRAY_FOREACH(m_cellSprites, cell_sprite) {
		stepCellSprites((CellSprite *)cell_sprite);
	}
}

void GameManager::stepCellSprites(CellSprite * cell_node) {
	cell_node -> move_random();
}

void GameManager::insertSpriteToStage(CCPoint loc) {
	Stage * stage = Stage::GetInstance();
	CellSprite * sprite = CellSprite::create();
	Stage::GetInstance() -> m_mother -> addChild(sprite, 500);
	sprite -> m_status = ecssNormal;
	sprite -> m_curLoc = loc;
	sprite -> m_tarLoc = loc;
	sprite -> setPosition(stage -> loc2pos(loc));
	sprite -> poll();
	sprite -> runAction_normal();
	m_cellSprites -> addObject(sprite);
}