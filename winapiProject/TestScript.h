#pragma once
#include <map>

#include "Script.h"
#include "UpdateCommand.h"
using namespace std;
class TestScript : public Script, public UpdateCommand
{
private:
	map<int, void(TestScript::*)()> Fnptrplay;
	int x;
	int y;
	int speed;
public:
	TestScript();
public:
	virtual void play();

private:
	void InputLogic();
	void Logic();

	void xplus();
	void xminus();
	void yplus();
	void yminus();
};

