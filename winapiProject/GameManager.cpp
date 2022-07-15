#include "GameManager.h"
#include "UpdateManager.h"
#include "Camera.h"
#include "InputManager.h"
#include "KeyInputManager.h"

GameManager::GameManager()
{
	updateManager = new UpdateManager();
	camera = new Camera();
	inputManager = new InputManager();
	keyinputManager = new KeyInputManager();
}

GameManager::~GameManager()
{
	delete updateManager;
	delete camera;
	delete inputManager;
	delete keyinputManager;
}

void GameManager::logicUpdate()
{
	inputManager->InputLogic();
	keyinputManager->InputLogic();
	updateManager->Updating();
	camera->Render();
}
