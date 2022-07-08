#include "GameManager.h"
#include "UpdateManager.h"
#include "Camera.h"
#include "InputManager.h"

GameManager::GameManager()
{
	updateManager = new UpdateManager();
	camera = new Camera();
	inputManager = new InputManager();
}

GameManager::~GameManager()
{
	delete updateManager;
	delete camera;
	delete inputManager;
}

void GameManager::logicUpdate()
{
	inputManager->InputLogic();
	updateManager->Updating();
	camera->Render();
}
