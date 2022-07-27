#pragma once

#include "Script.h"
#include "UpdateFunction.h"

class TextScript : public Script, public UpdateFunction
{
public:
	TextScript();
public:
	virtual void play();
};

