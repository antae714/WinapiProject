#include "E_Objtype.h"

string enumObj::conversion(const E_Objtype& p_enum) {
	switch (p_enum)
	{
	case E_Objtype::testLevel:
		return "testLevel";
	case E_Objtype::testLevel2:
		return "testLevel2";
	case E_Objtype::testPuzzel:
		return "testPuzzel";
	case E_Objtype::titlescreen:
		return "titlescreen";
	case E_Objtype::puzzlecleartest:
		return "puzzlecleartest";
	case E_Objtype::character:
		return "character";
	case E_Objtype::background:
		return "background";
	}
}

E_Objtype enumObj::conversion(const string& p_str) {
	if ("testLevel" == p_str)
		return E_Objtype::testLevel;
	else if ("testLevel2" == p_str)
			return E_Objtype::testLevel2;
	else if ("testPuzzel" == p_str)
		return E_Objtype::testPuzzel;
	else if ("titlescreen" == p_str)
		return E_Objtype::titlescreen;
	else if ("puzzlecleartest" == p_str)
		return E_Objtype::puzzlecleartest;
	else if ("character" == p_str)
		return E_Objtype::character;
	else if ("background" == p_str)
		return E_Objtype::background;
}

string enumObj::toFile(const E_Objtype& p_enum) {
	return string("./Resource/Level/") + conversion(p_enum) + ".txt";
}