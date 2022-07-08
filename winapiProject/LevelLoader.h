#pragma once

#include <string>
#include <vector>
#include <map>
#include <fstream>

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
	static GameObject* Initialize(vector<string>*, map<string, map<string, string>>*);
};

