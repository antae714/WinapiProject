#pragma once
#include <map>

#include "Script.h"
#include "UpdateFunction.h"

using namespace std;
class GameObject;
class TestScript : public Script, public UpdateFunction
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
	virtual void Update();

private:
	void InputLogic();
	void MoveLogic();
	void PuzzleLogic();

	void xplus();
	void xminus();
	void yplus();
	void yminus();
};

