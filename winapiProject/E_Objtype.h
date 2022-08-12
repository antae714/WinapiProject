#pragma once

#include <string>

using namespace std;

enum class E_Objtype
{

	empty = 0,
	level1_1,
	level1_2,
	level1_3,
	level1_4,
	level1_5,
	level1_6,
	level2_1,
	level2_2,
	level2_3,
	level2_4,
	level2_5,
	level2_6,
	testLevel,
	testLevel2,
	titlescreen,
	PuzzleBoard,
	puzzleType,
	testPuzzel,
	puzzleHint,
	puzzleliner,
	puzzleDot,
	puzzleMine,
	puzzleEnemy,
	puzzleAbility,
	character,
	PuzzleBoard_UI,
	Puzzleheart,
	puzzlecleartest,
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

