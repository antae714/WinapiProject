#pragma once

#include "Script.h"
#include "InputCommand.h"

class PuzzleExit : public Script, public InputCommand
{
public:
	PuzzleExit();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();
};

