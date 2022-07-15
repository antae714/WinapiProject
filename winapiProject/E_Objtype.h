#pragma once

#include <string>

using namespace std;

enum class E_Objtype
{
	testLevel = 0,
	testLevel2,
	testPuzzel,
	titlescreen,
	puzzlecleartest,
	character,
	background,

	MAX
};

namespace enumObj {;
string conversion(const E_Objtype&);
E_Objtype conversion(const string&);

string toFile(const E_Objtype&);
}

