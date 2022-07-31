#include "GameStart.h"
#include "LevelData.h"

GameStart::GameStart()
{
}

void GameStart::Input()
{
	LevelData::DeleteLevel("titlescreen");
	LevelData::LevelLode("testLevel");
	LevelData::LevelLode("character");
	LevelData::LevelLode("background");
}
