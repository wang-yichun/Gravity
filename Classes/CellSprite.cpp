#include "CellSprite.h"
#include "Stage.h"
#include "GameManager.h"

CellSprite::CellSprite():
	m_primarySprite(NULL)
{
}

CellSprite::~CellSprite() {
}

bool CellSprite::init() {
	m_primarySprite = CCSprite::createWithSpriteFrameName("cell_sprite/cell_sprite_01.png");
	if (m_primarySprite != NULL) {
		m_primarySprite -> setAnchorPoint(ccp(.5f, .0f));
		this -> addChild(m_primarySprite);
		m_status = ecssNormal;
		m_pollCode = enumMapCellPollCode::emcpcPoll;
	} else {
		return false;
	}
	return true;
}

void CellSprite::poll() {
	Stage * stage = Stage::GetInstance();
	stage -> cell(m_curLoc).setPollCode( this -> m_pollCode );
}

void CellSprite::move_random() {
	Stage * stage = Stage::GetInstance();
	if (this -> m_status == ecssNormal) {
		CCPoint curLoc = this -> m_curLoc;
		CCPoint tarLoc = this -> m_tarLoc;

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
			this -> m_tarLoc = dest;
			this -> beganMove();
		}
	}
}

void CellSprite::beganMove() {
	Stage * stage = Stage::GetInstance();
	m_status = ecssMove;
	//CCLOG("beganMove:(%f,%f)", m_tarLoc.x, m_tarLoc.y);
	CCPoint tarPos = stage -> loc2pos(m_tarLoc);
	CCActionInterval * delay = CCDelayTime::create(CCRANDOM_0_1());
	CCActionInterval * move = CCMoveTo::create(.5f, tarPos);
	CCCallFuncN * call = CCCallFuncN::create(this, callfuncN_selector(CellSprite::beganMove_over));
	CCSequence * sequence = CCSequence::create(delay, move, call, NULL);
	this -> runAction( sequence );
}

void CellSprite::beganMove_over(CCNode * pSender) {
	CellSprite * me = (CellSprite *)pSender;
	Stage * stage = Stage::GetInstance();
	me -> m_status = ecssNormal;
	me -> m_curLoc = m_tarLoc;
	this -> poll();
}

void CellSprite::runAction_normal() {
	unschedule(schedule_selector(CellSprite::runAction_normal_subFunc));
	scheduleOnce(schedule_selector(CellSprite::runAction_normal_subFunc), CCRANDOM_0_1());
}

void CellSprite::runAction_normal_subFunc(float dt) {
	CCActionInterval * jump = CCJumpTo::create(.5f, CCPointMake(0,0), 10.0f, 1);
	CCActionInterval * orange_in = CCScaleTo::create(.1f, 1.0f, .6f);
	CCActionInterval * orange_out = CCScaleTo::create(.1f, 1.0f, 1.0f);
	CCSequence * sequence = CCSequence::create(jump, orange_in, orange_out, NULL);
	CCActionInterval * repeat = CCRepeatForever::create(sequence);
	m_primarySprite -> runAction(repeat);
}