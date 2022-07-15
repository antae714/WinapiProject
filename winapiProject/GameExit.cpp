#include "GameExit.h"
#include "LevelData.h"
#include "GameData.h"

GameExit::GameExit()
{
}

void GameExit::play()
{
	GameData::getInstance()->setisgaming(false);
}
