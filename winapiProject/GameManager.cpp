#include "GameManager.h"
#include "UpdateManager.h"
#include "Camera.h"
#include "InputManager.h"
#include "KeyInputManager.h"
#include "SoundManager.h"
#include "GameTime.h"
#include "AllObject.h"

GameManager::GameManager()
{
	updateManager = new UpdateManager();
	camera = new Camera();
	inputManager = new InputManager();
	keyinputManager = new KeyInputManager();
	SoundManager::getInstance()->PlaySound_(E_Sound::BackGround);
}

GameManager::~GameManager()
{
	delete updateManager;
	delete camera;
	delete inputManager;
	delete keyinputManager;
	AllObject::deleteInstance();
}

void GameManager::logicUpdate()
{
	GameTime::getInstance()->TimeUpdate();
	inputManager->InputLogic();
	keyinputManager->InputLogic();
	updateManager->Updating();
	camera->Render();
}
