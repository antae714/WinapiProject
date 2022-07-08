#include "LevelData.h"
#include "AllObject.h"
#include "LevelLoader.h"

void LevelData::level1()
{
	AllObject::getInstance()->clear();

	LevelLoader::LoadLevel("./Resource/Level/testLevel.txt");
}

void LevelData::Puzzle1()
{
	LevelLoader::LoadLevel("./Resource/Level/testPuzzel.txt");
}

void LevelData::DeletePuzzle1()
{
	AllObject* allObject = AllObject::getInstance();
	allObject->deleteGroup("./Resource/Level/testPuzzel.txt");
}
