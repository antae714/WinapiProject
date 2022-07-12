#pragma once

#include <string>

using namespace std;

enum class E_Objtype;
class LevelData
{
public:
	static void LevelLode(const string&);
	static void LevelLode(const E_Objtype&);
	static void DeleteLevel(const string&);
	static void DeleteLevel(const E_Objtype&);
};