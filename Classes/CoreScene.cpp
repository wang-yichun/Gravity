#include "CoreScene.h"
#include "RoleLayer.h"
#include "AppMacros.h"
#include "GameLayer.h"
#include "SystemManager.h"
#include "GameManager.h"

CoreScene::CoreScene(void):
	uiWidget(NULL) 
{}

CoreScene::~CoreScene(void) {}

bool CoreScene::init() {

	// 
	UILayer * uiLayer = UILayer::create();
	uiWidget = GUIReader::shareReader()->widgetFromJsonFile("CSProj/game_ui_widget.ExportJson");
	uiWidget -> setTag(1);
	uiLayer -> addWidget(uiWidget);
	this -> addChild(uiLayer, 200, 2);


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