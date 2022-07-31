#include "E_Objtype.h"
#include "Macro.h"

string enumObj::conversion(const E_Objtype& p_enum) {
	switch (p_enum)
	{
		ENUMTOSTRING(E_Objtype, testLevel)
		ENUMTOSTRING(E_Objtype, testLevel2)
		ENUMTOSTRING(E_Objtype, testPuzzel)
		ENUMTOSTRING(E_Objtype, titlescreen)
		ENUMTOSTRING(E_Objtype, puzzleHint)
		ENUMTOSTRING(E_Objtype, puzzleliner)
		ENUMTOSTRING(E_Objtype, puzzlecleartest)
		ENUMTOSTRING(E_Objtype, character)
		ENUMTOSTRING(E_Objtype, background)
		ENUMTOSTRING(E_Objtype, PuzzleBoard)
		ENUMTOSTRING(E_Objtype, puzzleType)
			ENUMTOSTRING(E_Objtype, puzzleDot)
			ENUMTOSTRING(E_Objtype, text)
	}
}

E_Objtype enumObj::conversion(const string& p_str) {
	STRINGTOENUM(testLevel, E_Objtype)
		STRINGTOENUM(testLevel2, E_Objtype)
		STRINGTOENUM(testPuzzel, E_Objtype)
		STRINGTOENUM(titlescreen, E_Objtype)
		STRINGTOENUM(puzzleHint, E_Objtype)
		STRINGTOENUM(puzzleliner, E_Objtype)
		STRINGTOENUM(puzzlecleartest, E_Objtype)
		STRINGTOENUM(character, E_Objtype)
		STRINGTOENUM(background, E_Objtype)
		STRINGTOENUM(PuzzleBoard, E_Objtype)
		STRINGTOENUM(puzzleType, E_Objtype)
		STRINGTOENUM(puzzleDot, E_Objtype)
		STRINGTOENUM(text, E_Objtype)

		_ASSERT(0 && "ø¿≈∏?");
}

string enumObj::toFile(const E_Objtype& p_enum) {
	return string("./Resource/Level/") + conversion(p_enum) + ".txt";
}