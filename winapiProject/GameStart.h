#pragma once
#include "Script.h"
#include "InputFunction.h"

class GameStart : public Script, public InputFunction
{
public:
	GameStart();
public:
	virtual void play();
};