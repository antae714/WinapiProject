#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "Script.h"
#include "E_Script.h"

using namespace std;
class GameObject;
enum class E_Objtype;
class LevelLoader
{
public:
	static void LoadLevel(E_Objtype);

private:
	static void Parse(vector<string>*, map<string, map<string, string>>*, string);
	static string Layer2(string, map<string, map<string, string>>*, string);
	static GameObject* Initialize(E_Objtype, vector<string>*, map<string, map<string, string>>*);
	static Script* AllocScript(const E_Script&);
};

