#include "E_Script.h"
#include "Macro.h"

string enumScr::conversion(const E_Script& p_enum)
{
	switch (p_enum)
	{
		ENUMTOSTRING(E_Script, TestScript)
			ENUMTOSTRING(E_Script, TestScript2)
			ENUMTOSTRING(E_Script, TestScript3)
			ENUMTOSTRING(E_Script, GameStart)
			ENUMTOSTRING(E_Script, GameExit)
			ENUMTOSTRING(E_Script, MoveMap)
			ENUMTOSTRING(E_Script, PuzzleBoardScript)
			ENUMTOSTRING(E_Script, PuzzleDotScript)
			ENUMTOSTRING(E_Script, PuzzleEntry)
			ENUMTOSTRING(E_Script, PuzzleExit)
			ENUMTOSTRING(E_Script, LineScript)
			ENUMTOSTRING(E_Script, PlayerScript)
	}
}

E_Script enumScr::conversion(const string& p_str)
{
	STRINGTOENUM(TestScript, E_Script)
		STRINGTOENUM(TestScript2, E_Script)
		STRINGTOENUM(TestScript3, E_Script)
		STRINGTOENUM(GameStart, E_Script)
		STRINGTOENUM(GameExit, E_Script)
		STRINGTOENUM(MoveMap, E_Script)
		STRINGTOENUM(PuzzleBoardScript, E_Script)
		STRINGTOENUM(PuzzleDotScript, E_Script)
		STRINGTOENUM(PuzzleEntry, E_Script)
		STRINGTOENUM(PuzzleExit, E_Script)
		STRINGTOENUM(LineScript, E_Script)
		STRINGTOENUM(PlayerScript, E_Script)
}