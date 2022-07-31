#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleEntry : public Script, public KeyInputFunction
{
public:
	PuzzleEntry();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void KeyInput();
};

