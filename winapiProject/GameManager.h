#pragma once

class UpdateManager;
class InputManager;
class KeyInputManager;
class Camera;
class CollisonLogic;
class GameManager
{
private:
	UpdateManager* updateManager;
	InputManager* inputManager;
	KeyInputManager* keyinputManager;
	CollisonLogic* collisonLogic;
	Camera* camera;
public:
	GameManager();
	virtual ~GameManager();
public:
	void logicUpdate();
	//void InputLogic();
};

