#pragma once
#include "Script.h"
#include "UpdateFunction.h"

using namespace std;

class FailureCheck : public Script, public UpdateFunction
{
public:
	FailureCheck();
public:
	virtual void Update();
};