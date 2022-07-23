#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class TestScript3 : public Script, public KeyInputFunction
{
private:
	bool togle;
public:
	TestScript3();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();
};

