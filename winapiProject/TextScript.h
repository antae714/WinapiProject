#pragma once

#include "Script.h"
#include "UpdateFunction.h"
#include "KeyInputFunction.h"

class GameObject;
class TextScript : public Script, public KeyInputFunction
{
private:
	GameObject* textobj;
public:
	TextScript();
public:
	virtual void KeyInput();
};

