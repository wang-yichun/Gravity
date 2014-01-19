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
	Stage * stage = Stage::GetInstance();
	// 1. 在舞台增加几个cellsprite;
	for (int i = 0; i < 10; i++) {
		CellSprite * sprite = CellSprite::create();
		CCPoint loc = CCPointMake(0,i);
		sprite -> m_status = ecssNormal;
		sprite -> m_curLoc = loc;
		sprite -> m_tarLoc = loc;
		sprite -> setPosition(stage -> loc2pos(loc));
		sprite -> runAction_normal();
		Stage::GetInstance() -> m_mother -> addChild(sprite, 500);
		m_cellSprites -> addObject(sprite);
	}
}

void GameManager::stepStage() {
	CCObject * cell_sprite;
	CCARRAY_FOREACH(m_cellSprites, cell_sprite) {
		stepCellSprites((CellSprite *)cell_sprite);
	}
}

void GameManager::stepCellSprites(CellSprite * cell_node) {
	//CCLOG("GameManager::stepCellSprites %u", cell_node -> m_uID);
	Stage * stage = Stage::GetInstance();
	if (cell_node -> m_status == ecssNormal) {
		CCPoint curLoc = cell_node -> m_curLoc;
		CCPoint tarLoc = cell_node -> m_tarLoc;

		enumDirectSelectStatus select_status = edssNormal;
		int select_count = 0, select_max_count = 5;
		CCPoint dest;
		while (select_status == edssNormal) {
			if (curLoc.equals(tarLoc) == true) {
				// 需要发起一次随机移动通知;
				dest = curLoc;
				int dir = (int)(CCRANDOM_0_1() * 9);
				switch (dir) {
				case 0:{
					break;
					   }
				case 1:{
					dest.x += 1;
					break;
					   }
					   break;
				case 2:{
					dest.x += 1;
					dest.y += 1;
					break;
					   }
					   break;
				case 3:{
					dest.y += 1;
					break;
					   }
				case 4:{
					dest.x -= 1;
					dest.y += 1;
					break;
					   }
				case 5:{
					dest.x -= 1;
					break;
					   }
					   break;
				case 6:{
					dest.x -= 1;
					dest.y -= 1;
					break;
					   }
					   break;
				case 7:{
					dest.y -= 1;
					break;
					   }
				case 8:{
					dest.x += 1;
					dest.y -= 1;
					break;
					   }
				default:
					break;
				}
				if (stage -> isInScope(dest)) { // 首先保证在整体范围内;
					if ( MapCell::GetCellCodeIsNullShow( stage -> cell(dest).code ) == false ) {
						select_status = edssSuccess;
					}
				}
				if (++select_count >= select_max_count) {
					select_status = edssFailed;
				}
			}
		}
		
		if (select_status == edssSuccess){
			cell_node -> m_tarLoc = dest;
			cell_node -> beganMove();
		}
	}
}