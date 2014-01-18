#include "CoreScene.h"
#include "RoleLayer.h"
#include "AppMacros.h"
#include "GameLayer.h"

CoreScene::CoreScene(void) {}

CoreScene::~CoreScene(void) {}

bool CoreScene::init() {
	GameLayer * gameLayer = GameLayer::create();
	//gameLayer -> setPositionY(50);
	this -> addChild(gameLayer, 100, 1);

	Stage::GetInstance() -> setMother(gameLayer);
	Stage::GetInstance() -> resetMap();
	Stage::GetInstance() -> refleshCellShow_adv();

	SystemManager::GetInstance(); // init
	return true;
}