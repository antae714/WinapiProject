#pragma once
#include "Script.h"
#include "UpdateFunction.h"
using namespace std;

class UI_Hit : public Script, public UpdateFunction
{
private:
	double cooldown;
	bool cooldown_sw;

public:
	UI_Hit();
public:
	virtual void Update();
	void Hit();
};