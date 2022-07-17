#pragma once

#include <string>

using namespace std;
enum class E_Sound
{
	BackGround = 0,
	Click,

	MAX
};

namespace enumSound {;
string conversion(const E_Sound&);
E_Sound conversion(const string&);
string toFile(const E_Sound&);
}

