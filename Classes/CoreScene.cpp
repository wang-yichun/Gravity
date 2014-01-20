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


	// ���ص�ͼ;
	startStage();

	return true;
}

void CoreScene::step(float dt) {
	GameManager::GetInstance() -> stepStage();
}

void CoreScene::startStage() {
	//Stage::GetInstance() -> resetMap();
	SystemManager::GetInstance() -> do_load_map();
	// ������ʾ��ͼ;
	Stage::GetInstance() -> refleshCellShow_adv();
	// ׼����ͼ����Ԫ��;
	GameManager::GetInstance() -> prepareStage(); // init
	// ���ö�ʱ��;
	schedule(schedule_selector(CoreScene::step), 1.0f);
}