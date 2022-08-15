#pragma once

#include "Script.h"
#include "UpdateFunction.h"
#include "KeyInputFunction.h"
#include <string>

using namespace std;

class GameObject;
class TextScript : public Script, public KeyInputFunction
{
private:
	GameObject* textobj;
	bool sw;
	string dialog;
	string varias;
	int value;
public:
	TextScript();
public:
	virtual void KeyInput();
	virtual void Set(string);
	virtual void Set(string, string, int);
};

