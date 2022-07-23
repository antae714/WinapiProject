#pragma once
#include "Script.h"
#include "InputFunction.h"

class GameExit : public Script, public InputFunction
{
public:
	GameExit();
public:
	virtual void play();
};