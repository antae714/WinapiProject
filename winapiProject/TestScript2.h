#pragma once

#include "Script.h"
#include "InputCommand.h"

class TestScript2 : public Script, public InputCommand
{
private:
	bool isClicked;
public:
	TestScript2();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();
};

