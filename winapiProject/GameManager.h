#pragma once

class UpdateManager;
class InputManager;
class Camera;
class GameManager
{
private:
	UpdateManager* updateManager;
	InputManager* inputManager;
	Camera* camera;
public:
	GameManager();
	virtual ~GameManager();
public:
	void logicUpdate();
};

