#pragma once

#include <string>

using namespace std;
enum class E_Sound
{
// BGM
	BackGround = 0,
	Puzzle,
	
// BGS
	Timer,

// SE
	Click,
	Hit,

	MAX
};

namespace enumSound {;
string conversion(const E_Sound&);
E_Sound conversion(const string&);
string toFile(const E_Sound&);
}

