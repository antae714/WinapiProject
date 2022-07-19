#pragma once
#include <map>

#include "Script.h"
#include "UpdateCommand.h"

using namespace std;

class PlayerScript : public Script, public UpdateCommand
{
private:
	map<int, void(PlayerScript::*)()> Fnptrplay;
	int x;
	int y;
	int speed;

	int top;
	int bottom;
	int left;
	int right;
public:
	PlayerScript();
public:
	virtual void play();
	void SetMovableArea();
	void SetMovableArea(int, int, int, int);

private:
	void InputLogic();
	void MoveLogic();

	void xplus();
	void xminus();
	void yplus();
	void yminus();
};