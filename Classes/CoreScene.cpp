#include "CoreScene.h"
#include "RoleLayer.h"

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
	return true;
}