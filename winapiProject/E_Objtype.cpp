#include "E_Objtype.h"

string enumObj::conversion(const E_Objtype& p_enum) {
	switch (p_enum)
	{
	case E_Objtype::testLevel:
		return "testLevel";
	case E_Objtype::testPuzzel:
		return "testPuzzel";
	}
}

E_Objtype enumObj::conversion(const string& p_str) {
	if ("testLevel" == p_str)
		return E_Objtype::testLevel;
	else if ("testPuzzel" == p_str)
		return E_Objtype::testPuzzel;
}

string enumObj::toFile(const E_Objtype& p_enum) {
	return string("./Resource/Level/") + conversion(p_enum) + ".txt";
}