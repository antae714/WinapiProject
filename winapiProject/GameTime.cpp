#include "GameTime.h"

GameTime::GameTime()
{
	start = system_clock::now();
	end = start;
	deltaTime = end - start;
}

GameTime::~GameTime()
{
}

void GameTime::TimeUpdate()
{
	end = system_clock::now();
	deltaTime = end - start;
	start = end;
}

double GameTime::getdeltaTime()
{
	return deltaTime.count();
}
