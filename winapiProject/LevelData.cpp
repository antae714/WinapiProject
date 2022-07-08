#include "LevelData.h"
#include "AllObject.h"
#include "LevelLoader.h"
#include "E_Objtype.h"

void LevelData::level1()
{
	AllObject::getInstance()->clear();

	LevelLoader::LoadLevel(E_Objtype::testLevel);
}

void LevelData::Puzzle1()
{
	LevelLoader::LoadLevel(E_Objtype::testPuzzel);
}

void LevelData::DeletePuzzle1()
{
	AllObject* allObject = AllObject::getInstance();
	allObject->deleteGroup(E_Objtype::testPuzzel);
}
