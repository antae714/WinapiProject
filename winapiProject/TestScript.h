#pragma once
#include <map>

#include "Script.h"
#include "UpdateCommand.h"

using namespace std;
class GameObject;
class TestScript : public Script, public UpdateCommand
{
private:
	map<int, void(TestScript::*)()> Fnptrplay;
	GameObject* line;
	int x;
	int y;
	int speed;
public:
	TestScript();
public:
	virtual void play();

private:
	void InputLogic();
	void MoveLogic();
	void PuzzleLogic();

	void xplus();
	void xminus();
	void yplus();
	void yminus();
};

