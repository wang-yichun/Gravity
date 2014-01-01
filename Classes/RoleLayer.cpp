#include "RoleLayer.h"
#include "AppMacros.h"

RoleLayer::RoleLayer() {}

RoleLayer::~RoleLayer() {}

bool RoleLayer::init() {
	this->setContentSize(designResolutionSize);
	//CCSprite *role = CCSprite::createWithSpriteFrameName("Apple.png");
	//role->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	//this->addChild(role);

	// test tile map
	CCTMXTiledMap *tiledMap = CCTMXTiledMap::create("testmap.tmx");
	tiledMap->setAnchorPoint(ccp(.5,.5));
	tiledMap->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	this->addChild(tiledMap);

	// kDebugLabel
	CCLabelTTF *pDebugLabel = CCLabelTTF::create("", "Arial", 40);
	pDebugLabel->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	pDebugLabel->setString("init");
	this->addChild(pDebugLabel, 10, kDebugLabel);
	return true;
}

void RoleLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent) {
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch *touch = (CCTouch *)*it;
		int id = touch->getID();
		CCString * id_str = CCString::createWithFormat("began: %d",id);
		((CCLabelTTF *)this->getChildByTag(kDebugLabel))->setString(id_str->getCString());
		CCLOGINFO("%s", id_str->getCString());
	}
}

void RoleLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent) {
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch *touch = (CCTouch *)*it;
		int id = touch->getID();
		CCString * id_str = CCString::createWithFormat("moved: %d",id);
		((CCLabelTTF *)this->getChildByTag(kDebugLabel))->setString(id_str->getCString());
		CCLOGINFO("%s", id_str->getCString());
	}
}

void RoleLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent) {
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch *touch = (CCTouch *)*it;
		int id = touch->getID();
		CCString * id_str = CCString::createWithFormat("ended: %d",id);
		((CCLabelTTF *)this->getChildByTag(kDebugLabel))->setString(id_str->getCString());
		CCLOGINFO("%s", id_str->getCString());
	}
}

void RoleLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent) {
	for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
		CCTouch *touch = (CCTouch *)*it;
		int id = touch->getID();
		CCString * id_str = CCString::createWithFormat("cancelled: %d",id);
		((CCLabelTTF *)this->getChildByTag(kDebugLabel))->setString(id_str->getCString());
		CCLOGINFO("%s", id_str->getCString());
	}
}