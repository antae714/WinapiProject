#pragma once

#include <string>

using namespace std;

enum class E_Script
{
	TestScript,
	TestScript2,
	TestScript3,
	GameStart,
	GameExit,
	MoveMap,
	PuzzleBoardScript,
	PuzzleDotScript,
	PuzzleEntry,
	PuzzleExit,
	LineScript,
	PlayerScript,
	TextScript,

	MAX
};

namespace enumScr {;

string conversion(const E_Script&);
E_Script conversion(const string&);
}

