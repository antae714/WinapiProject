#pragma once

#include <chrono>
#include "SingletonCls.h"

using namespace std;
using namespace chrono;

class GameTime : public SingletonCls<GameTime>
{
private:
	system_clock::time_point start;
	system_clock::time_point end;
	duration<double> deltaTime;

public:
	GameTime();
	virtual ~GameTime();

public:
	void TimeUpdate();

	double getdeltaTime();
};

