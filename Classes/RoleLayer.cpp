#include "RoleLayer.h"
#include "AppMacros.h"

RoleLayer::RoleLayer() {}

RoleLayer::~RoleLayer() {}

bool RoleLayer::init() {
	CCLayer::init();

	//this->setContentSize(designResolutionSize);
	//CCSprite *role = CCSprite::createWithSpriteFrameName("Apple.png");
	//role->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	//this->addChild(role);

	// test tile map
	//CCTMXTiledMap *tiledMap = CCTMXTiledMap::create("testmap.tmx");
	//tiledMap->setAnchorPoint(ccp(.5,.5));
	//tiledMap->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	//this->addChild(tiledMap);

	// kDebugLabel
	CCLabelTTF *pDebugLabel = CCLabelTTF::create("", "Arial", 40);
	pDebugLabel->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	pDebugLabel->setString("init");
	this->addChild(pDebugLabel, 100, kDebugLabel);

	// control btn
	CCScale9Sprite * btnNormal = CCScale9Sprite::createWithSpriteFrameName("Acorn_Squash.png");
	CCScale9Sprite* btnDown = CCScale9Sprite::createWithSpriteFrameName("Apple.png");
	CCLabelTTF * ttf_down = CCLabelTTF::create("[Down]", "Arial", 60);
	CCControlButton * cb_down = CCControlButton::create(ttf_down, btnNormal);  
	cb_down->setBackgroundSpriteForState(btnDown, CCControlStateSelected); 
	cb_down->setPosition(ccp(600,60));
	this->addChild(cb_down, 100, kDownControl);

	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_on), CCControlEventTouchDown);  
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_on), CCControlEventTouchDragEnter);  
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_off), CCControlEventTouchDragExit);  
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_on), CCControlEventTouchDragInside);  
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_off), CCControlEventTouchDragOutside);  
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_off), CCControlEventTouchUpInside);  
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_off), CCControlEventTouchUpOutside);
	cb_down->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::down_power_off), CCControlEventTouchCancel);  

	// control btn
	CCScale9Sprite * btnNormal2 = CCScale9Sprite::createWithSpriteFrameName("Acorn_Squash.png");
	CCScale9Sprite* btnDown2 = CCScale9Sprite::createWithSpriteFrameName("Apple.png");
	CCLabelTTF * ttf_left = CCLabelTTF::create("[left]", "Arial", 60);
	CCControlButton * cb_left = CCControlButton::create(ttf_left, btnNormal2);  
	cb_left->setBackgroundSpriteForState(btnDown2, CCControlStateSelected); 
	cb_left->setPosition(ccp(100,60));
	this->addChild(cb_left, 100, kDownControl);

	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_on), CCControlEventTouchDown);  
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_on), CCControlEventTouchDragEnter);  
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_off), CCControlEventTouchDragExit);  
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_on), CCControlEventTouchDragInside);  
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_off), CCControlEventTouchDragOutside);  
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_off), CCControlEventTouchUpInside);  
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_off), CCControlEventTouchUpOutside);
	cb_left->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::left_power_off), CCControlEventTouchCancel);  

	// control btn
	CCScale9Sprite * btnNormal3 = CCScale9Sprite::createWithSpriteFrameName("Acorn_Squash.png");
	CCScale9Sprite* btnDown3 = CCScale9Sprite::createWithSpriteFrameName("Apple.png");
	CCLabelTTF * ttf_right = CCLabelTTF::create("[right]", "Arial", 60);
	CCControlButton * cb_right = CCControlButton::create(ttf_right, btnNormal3);  
	cb_right->setBackgroundSpriteForState(btnDown3, CCControlStateSelected); 
	cb_right->setPosition(ccp(1180,60));
	this->addChild(cb_right, 100, kDownControl);

	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_on), CCControlEventTouchDown);  
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_on), CCControlEventTouchDragEnter);  
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_off), CCControlEventTouchDragExit);  
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_on), CCControlEventTouchDragInside);  
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_off), CCControlEventTouchDragOutside);  
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_off), CCControlEventTouchUpInside);  
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_off), CCControlEventTouchUpOutside);
	cb_right->addTargetWithActionForControlEvents(this, cccontrol_selector(RoleLayer::right_power_off), CCControlEventTouchCancel);  


	// space ship
	CCSprite * ship = CCSprite::create("space_ship.png");
	ship->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
	this->addChild(ship, 50, kShip);

	// data init
	ai[0] = ai[1] = ai[2] = ccp(0,0);
	a = CCPointMake(0,0);
	v = CCPointMake(0,0);
	schedule(schedule_selector(RoleLayer::step));
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

void RoleLayer::step(float dt) {

	a = ai[0] + ai[1] + ai[2];

	v = v + a;
	v = v * .99;

	v.y -= .01f;
	CCSprite * ship = (CCSprite *)getChildByTag(kShip);
	ship->setPositionX(ship->getPositionX()+v.x);
	ship->setPositionY(ship->getPositionY()+v.y);

}


void RoleLayer::left_power_on(CCObject* pSender, CCControlEvent event) {
	ai[0].x = .02f;
	ai[0].y = .0f;
}

void RoleLayer::left_power_off(CCObject* pSender, CCControlEvent event) {
	ai[0].x = .0f;
	ai[0].y = .0f;
}   

void RoleLayer::down_power_on(CCObject* pSender, CCControlEvent event) {
	ai[1].x = .0f;
	ai[1].y = .02f;
}

void RoleLayer::down_power_off(CCObject* pSender, CCControlEvent event) {
	ai[1].x = .0f;
	ai[1].y = .0f;
} 

void RoleLayer::right_power_on(CCObject* pSender, CCControlEvent event){
	ai[2].x = -.02f;
	ai[2].y = .0f;
}

void RoleLayer::right_power_off(CCObject* pSender, CCControlEvent event){
	ai[2].x = .0f;
	ai[2].y = .0f;
} 