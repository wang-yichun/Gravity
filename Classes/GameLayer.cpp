#include "GameLayer.h"

GameLayer::GameLayer()
{}

GameLayer::~GameLayer()
{}

bool GameLayer::init() {
	CCLayerColor::init();
	setContentSize(CCSizeMake(1280,800));
	setColor(ccc3(40,40,40));
	setOpacity(255);
	setTouchEnabled(true);
	return true;
}

void GameLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent) {
	CCLOG("GameLayer::ccTouchesBegan");
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch * pTouch = dynamic_cast<CCTouch *>(*it);
		CCPoint pos = this -> convertTouchToNodeSpace(pTouch);
		if (Stage::GetInstance()->isInScope(pos, true)) {
			CCPoint loc = Stage::GetInstance()->pos2loc(pos);
			int idx = Stage::GetInstance()->pos2idx(pos);
			CCLOGINFO("ccTouchesBegan pos:(%f,%f) loc:(%f,%f) idx:(%d) tID:(%d)", pos.x, pos.y, loc.x, loc.y, idx, pTouch->getID());
			
			// USER OPERATE
#if PROGRAM_MODE == PROGRAM_MODE_GAME
			// TODO:
#elif PROGRAM_MODE == PROGRAM_MODE_CREATER
			enumMapCellCode cell_code = SystemManager::GetInstance()->m_chosedCellCode;
			enumMapCellPollCode cell_poll_code = SystemManager::GetInstance()->m_chosedCellPollCode;
			Stage::GetInstance()->cell(idx).setCode(cell_code);
			Stage::GetInstance()->cell(idx).setPollCode(cell_poll_code);
			Stage::GetInstance()->refleshCellShow_adv_nine(loc);
#else
	CCAssert(false, "PROGRAM_MODE unexpect.");
#endif
			
		}
	}
}

void GameLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent) {
	CCLOG("GameLayer::ccTouchesMoved");
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch * pTouch = dynamic_cast<CCTouch *>(*it);
		CCPoint pos = this -> convertTouchToNodeSpace(pTouch);
		if (Stage::GetInstance()->isInScope(pos, true)) {
			CCPoint loc = Stage::GetInstance()->pos2loc(pos);
			int idx = Stage::GetInstance()->pos2idx(pos);
			CCLOGINFO("ccTouchesMoved pos:(%f,%f) loc:(%f,%f) idx:(%d) tID:(%d)", pos.x, pos.y, loc.x, loc.y, idx, pTouch->getID());
			
			// USER OPERATE
#if PROGRAM_MODE == PROGRAM_MODE_GAME
			// TODO:
#elif PROGRAM_MODE == PROGRAM_MODE_CREATER
			enumMapCellCode cell_code = SystemManager::GetInstance()->m_chosedCellCode;
			enumMapCellPollCode cell_poll_code = SystemManager::GetInstance()->m_chosedCellPollCode;
			Stage::GetInstance()->cell(idx).setCode(cell_code);
			Stage::GetInstance()->cell(idx).setPollCode(cell_poll_code);
			Stage::GetInstance()->refleshCellShow_adv_nine(loc);
#else
			CCAssert(false, "PROGRAM_MODE unexpect.");
#endif

		}
	}
}

void GameLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent) {
	CCLOG("GameLayer::ccTouchesEnded");
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch * pTouch = dynamic_cast<CCTouch *>(*it);
		CCPoint pos = this -> convertTouchToNodeSpace(pTouch);
		if (Stage::GetInstance()->isInScope(pos, true)) {
			CCPoint loc = Stage::GetInstance()->pos2loc(pos);
			int idx = Stage::GetInstance()->pos2idx(pos);
			CCLOGINFO("ccTouchesEnded pos:(%f,%f) loc:(%f,%f) idx:(%d) tID:(%d)", pos.x, pos.y, loc.x, loc.y, idx, pTouch->getID());
			
			// USER OPERATE
#if PROGRAM_MODE == PROGRAM_MODE_GAME
			// TODO:
			GameManager::GetInstance() -> touchAPoint(loc);
#elif PROGRAM_MODE == PROGRAM_MODE_CREATER
			enumMapCellCode cell_code = SystemManager::GetInstance()->m_chosedCellCode;
			enumMapCellPollCode cell_poll_code = SystemManager::GetInstance()->m_chosedCellPollCode;
			Stage::GetInstance()->cell(idx).setCode(cell_code);
			Stage::GetInstance()->cell(idx).setPollCode(cell_poll_code);
			Stage::GetInstance()->refleshCellShow_adv_nine(loc);
#else
			CCAssert(false, "PROGRAM_MODE unexpect.");
#endif

		}
	}
}

void GameLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent) {
	CCLOG("GameLayer::ccTouchesCancelled");
}