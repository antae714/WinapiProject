#pragma once
#include "Command.h"
#include "Vector2.h"

class InputCommand : public Command
{
public:
	//클릭되었을때 실행시킬 함수
	virtual void play() = 0;
};

