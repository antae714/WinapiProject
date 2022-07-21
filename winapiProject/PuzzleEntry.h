#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class PuzzleEntry : public Script, public KeyInputCommand
{
public:
	PuzzleEntry();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();
	void testplay();
};

