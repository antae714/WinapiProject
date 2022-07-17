#pragma once

class UpdateManager;
class InputManager;
class KeyInputManager;
class Camera;
class SoundManager;
class GameManager
{
private:
	UpdateManager* updateManager;
	InputManager* inputManager;
	KeyInputManager* keyinputManager;
	Camera* camera;
public:
	GameManager();
	virtual ~GameManager();
public:
	void logicUpdate();
};

