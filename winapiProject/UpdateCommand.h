#pragma once
#include "Command.h"


class UpdateCommand : public Command
{
public:
	//업데이트때 실행시킬 함수
	virtual void play() = 0;
};

