#include "LevelData.h"
#include "AllObject.h"
#include "LevelLoader.h"
#include "E_Objtype.h"

void LevelData::LevelLode(const string& p_str)
{
	E_Objtype objtype = enumObj::conversion(p_str);
	LevelLode(objtype);
}

void LevelData::LevelLode(const E_Objtype& p_objtype) {

	LevelLoader::LoadLevel(p_objtype);
}

void LevelData::DeleteLevel(const string& p_str)
{
	E_Objtype objtype = enumObj::conversion(p_str);
	DeleteLevel(objtype);
}

void LevelData::DeleteLevel(const E_Objtype& p_objtype) {

	AllObject* allObject = AllObject::getInstance();
	allObject->deleteGroup(p_objtype);
}
