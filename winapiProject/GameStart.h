#pragma once
#include "Script.h"
#include "InputCommand.h"

class GameStart : public Script, public InputCommand
{
public:
	GameStart();
public:
	virtual void play();
};