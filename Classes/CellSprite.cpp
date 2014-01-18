#include "CellSprite.h"

CellSprite::CellSprite():
	m_primarySprite(NULL) {
}

CellSprite::~CellSprite() {
}

bool CellSprite::init() {
	m_primarySprite -> CCSprite::createWithSpriteFrameName("cell_sprite/cell_sprite_01.png");
	if (m_primarySprite != NULL) {
		this -> addChild(m_primarySprite);
	}
	return true;
}

void CellSprite::runAction_normal() {
	CCActionInterval * jump = CCJumpTo::create(.5f, CCPointMake(0,0), 10.0f, 2);
	CCActionInterval * repeat = CCRepeatForever::create(jump);
	m_primarySprite -> runAction(repeat);
}
