#pragma once
#include "Script.h"
#include "UpdateFunction.h"
using namespace std;

class Timer : public Script, public UpdateFunction
{
private:
	int count;
	double time;

public:
	Timer();
public:
	virtual void Update();
	int getTime();
};