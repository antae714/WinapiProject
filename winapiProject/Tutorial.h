#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class Tutorial : public Script, public KeyInputFunction
{
private:
	int page;
public:
	Tutorial();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void KeyInput();
};
