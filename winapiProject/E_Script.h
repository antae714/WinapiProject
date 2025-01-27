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
	MoveMap2,
	PuzzleBoardScript,
	PuzzleDotScript,
	PuzzleEntry,
	PuzzleExit,
	LineScript,
	PlayerScript,
	TextScript,
	UI_Hit,
	Life,
	Timer,
	FailureCheck,
	LevelUpdater,

	MAX
};

namespace enumScr {;

string conversion(const E_Script&);
E_Script conversion(const string&);
}

