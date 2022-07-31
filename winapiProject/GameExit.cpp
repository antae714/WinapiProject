#include "GameExit.h"
#include "LevelData.h"
#include "GameData.h"

GameExit::GameExit()
{
}

void GameExit::Input()
{
	GameData::getInstance()->setisgaming(false);
}
