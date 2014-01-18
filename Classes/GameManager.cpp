#include "GameManager.h"

GameManager * GameManager::s_GameManager = NULL;

GameManager::GameManager() {
}

GameManager::~GameManager() {
}

bool GameManager::init() {
	return true;
}

GameManager * GameManager::GetInstance() {
	if (s_GameManager == NULL) {
		s_GameManager = new GameManager();
		s_GameManager -> init();
	}
	return s_GameManager;
}