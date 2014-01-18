#include "CoreScene.h"
#include "RoleLayer.h"
#include "AppMacros.h"
#include "GameLayer.h"
#include "SystemManager.h"
#include "GameManager.h"

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

	GameManager::GetInstance() -> prepareStage(); // init
	
	schedule(schedule_selector(CoreScene::step), 1.0f);

	return true;
}

void CoreScene::step(float dt) {
	GameManager::GetInstance() -> stepStage();
}