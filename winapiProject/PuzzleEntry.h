#pragma once

#include <string>
#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleEntry : public Script, public KeyInputFunction
{
private:
	string str;
public:
	PuzzleEntry();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void KeyInput();
	virtual void Set(string);
};

