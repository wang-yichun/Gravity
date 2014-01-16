#include "CoreScene.h"
#include "RoleLayer.h"
#include "AppMacros.h"

CoreScene::CoreScene(void) {}

CoreScene::~CoreScene(void) {}

bool CoreScene::init() {
	RoleLayer * role_layer = RoleLayer::create();
	CCLOGINFO("Pos(%f,%f) Size(%f,%f) Anc(%f,%f) ", 
		role_layer->getPositionX(), 
		role_layer->getPositionY(), 
		role_layer->getContentSize().width, 
		role_layer->getContentSize().height,
		role_layer->getAnchorPoint().x,
		role_layer->getAnchorPoint().y);
	role_layer->setTouchEnabled(true);
	this->addChild(role_layer, 200, kRoleLayer);

	CCSprite * bg_sprite = CCSprite::create("bg.png");
	CCLayer * bg_layer = CCLayer::create();
	bg_sprite->setPosition(ccp(bg_layer->getContentSize().width/2,bg_layer->getContentSize().height/2));
	bg_layer->addChild(bg_sprite);
	this->addChild(bg_layer, 100, kBgLayer);
	return true;
}