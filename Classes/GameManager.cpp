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

void GameManager::touchAPoint(CCPoint loc) {
	Stage * stage = Stage::GetInstance();
	if (stage -> cell(loc).poll_code == emcpcPoll) {
		insertSpriteToStage(loc);
	} else {
		// TODO: 提示:请在污染格内放置精灵;
	}
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