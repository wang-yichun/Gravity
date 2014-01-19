#include "CellSprite.h"
#include "Stage.h"

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
	} else {
		return false;
	}
	return true;
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
	me -> m_status = ecssNormal;
	me -> m_curLoc = m_tarLoc;
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