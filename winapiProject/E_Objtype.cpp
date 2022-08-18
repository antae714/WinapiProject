#include "E_Objtype.h"
#include "Macro.h"

string enumObj::conversion(const E_Objtype& p_enum) {
	switch (p_enum)
	{
		ENUMTOSTRING(E_Objtype, level1_1)
		ENUMTOSTRING(E_Objtype, level1_2)
		ENUMTOSTRING(E_Objtype, level1_3)
		ENUMTOSTRING(E_Objtype, level1_4)
		ENUMTOSTRING(E_Objtype, level1_5)
		ENUMTOSTRING(E_Objtype, level1_6)
		ENUMTOSTRING(E_Objtype, level2_1)
		ENUMTOSTRING(E_Objtype, level2_2)
		ENUMTOSTRING(E_Objtype, level2_3)
		ENUMTOSTRING(E_Objtype, level2_4)
		ENUMTOSTRING(E_Objtype, level2_5)
		ENUMTOSTRING(E_Objtype, level2_6)
		ENUMTOSTRING(E_Objtype, testLevel)
		ENUMTOSTRING(E_Objtype, testLevel2)
		ENUMTOSTRING(E_Objtype, testPuzzel)
		ENUMTOSTRING(E_Objtype, titlescreen)
		ENUMTOSTRING(E_Objtype, puzzleHint)
		ENUMTOSTRING(E_Objtype, puzzleliner)
		ENUMTOSTRING(E_Objtype, puzzlecleartest)
		ENUMTOSTRING(E_Objtype, character)
		ENUMTOSTRING(E_Objtype, background)
			ENUMTOSTRING(E_Objtype, Tutorial)
		ENUMTOSTRING(E_Objtype, PuzzleBoard)
			ENUMTOSTRING(E_Objtype, PuzzleBoard_UI)
			ENUMTOSTRING(E_Objtype, Puzzleheart)
		ENUMTOSTRING(E_Objtype, puzzleType)
		ENUMTOSTRING(E_Objtype, puzzleDot)
			ENUMTOSTRING(E_Objtype, puzzleMine)
			ENUMTOSTRING(E_Objtype, puzzleEnemy)
		ENUMTOSTRING(E_Objtype, puzzleAbility)
		ENUMTOSTRING(E_Objtype, text)
	}
}

E_Objtype enumObj::conversion(const string& p_str) {
	STRINGTOENUM(E_Objtype, level1_1)
	STRINGTOENUM(E_Objtype, level1_2)
	STRINGTOENUM(E_Objtype, level1_3)
	STRINGTOENUM(E_Objtype, level1_4)
	STRINGTOENUM(E_Objtype, level1_5)
	STRINGTOENUM(E_Objtype, level1_6)
	STRINGTOENUM(E_Objtype, level2_1)
	STRINGTOENUM(E_Objtype, level2_2)
	STRINGTOENUM(E_Objtype, level2_3)
	STRINGTOENUM(E_Objtype, level2_4)
	STRINGTOENUM(E_Objtype, level2_5)
	STRINGTOENUM(E_Objtype, level2_6)
	STRINGTOENUM(E_Objtype, testLevel)
	STRINGTOENUM(E_Objtype, testLevel2)
	STRINGTOENUM(E_Objtype, testPuzzel)
	STRINGTOENUM(E_Objtype, titlescreen)
	STRINGTOENUM(E_Objtype, puzzleHint)
	STRINGTOENUM(E_Objtype, puzzleliner)
	STRINGTOENUM(E_Objtype, puzzlecleartest)
	STRINGTOENUM(E_Objtype, character)
	STRINGTOENUM(E_Objtype, background)
		STRINGTOENUM(E_Objtype, Tutorial)
	STRINGTOENUM(E_Objtype, PuzzleBoard)
	STRINGTOENUM(E_Objtype, PuzzleBoard_UI)
		STRINGTOENUM(E_Objtype, Puzzleheart)
	STRINGTOENUM(E_Objtype, puzzleType)
	STRINGTOENUM(E_Objtype, puzzleDot)
	STRINGTOENUM(E_Objtype, puzzleMine)
	STRINGTOENUM(E_Objtype, puzzleEnemy)
	STRINGTOENUM(E_Objtype, puzzleAbility)
	STRINGTOENUM(E_Objtype, text)

	_ASSERT(0 && "ø¿≈∏?");
}

string enumObj::toFile(const E_Objtype& p_enum) {
	return string("./Resource/Level/") + conversion(p_enum) + ".txt";
}