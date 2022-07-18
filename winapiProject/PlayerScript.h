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
public:
	PlayerScript();
public:
	virtual void play();

private:
	void InputLogic();
	void MoveLogic();

	void xplus();
	void xminus();
	void yplus();
	void yminus();
};