#pragma once
#include "Script.h"
#include "InputCommand.h"

class GameExit : public Script, public InputCommand
{
public:
	GameExit();
public:
	virtual void play();
};