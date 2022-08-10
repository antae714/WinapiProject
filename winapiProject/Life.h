#pragma once
#include "Script.h"
#include "UpdateFunction.h"
using namespace std;

class Life : public Script, public UpdateFunction
{
private:
	int life;

public:
	Life();
public:
	virtual void Update();
};