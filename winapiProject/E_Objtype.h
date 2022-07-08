#pragma once

#include <string>

using namespace std;

enum class E_Objtype
{
	testLevel = 0,
	testPuzzel,

	MAX
};

namespace enumObj {;
string conversion(const E_Objtype&);
E_Objtype conversion(const string&);

string toFile(const E_Objtype&);
}

