#pragma once
#include "Script.h"
#include "UpdateCommand.h"

class TestScript : public Script, public UpdateCommand
{
public:
	virtual void play();
};

