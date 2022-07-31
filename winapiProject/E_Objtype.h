#pragma once

#include <string>

using namespace std;

enum class E_Objtype
{
	empty = 0,
	testLevel,
	testLevel2,
	titlescreen,
	PuzzleBoard,
	puzzleType,
	testPuzzel,
	puzzleHint,
	puzzleliner,
	puzzleDot,
	puzzlecleartest,
	character,
	background,

	UI,

	text,

	MAX
};

namespace enumObj {;
string conversion(const E_Objtype&);
E_Objtype conversion(const string&);

string toFile(const E_Objtype&);
}

