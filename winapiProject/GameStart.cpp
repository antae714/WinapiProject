#include "GameStart.h"
#include "LevelData.h"

GameStart::GameStart()
{
}

void GameStart::Input()
{
	LevelData::DeleteLevel("titlescreen");
	LevelData::LevelLode("level1_1");
	LevelData::LevelLode("character");
	LevelData::LevelLode("background");
}
