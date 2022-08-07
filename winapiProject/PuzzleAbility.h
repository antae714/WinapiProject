#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleAbility : public Script, public KeyInputFunction
{
public:
	PuzzleAbility();
public:
	virtual void KeyInput();

};