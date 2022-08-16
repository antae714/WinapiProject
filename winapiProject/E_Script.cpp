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
			ENUMTOSTRING(E_Script, MoveMap2)
			ENUMTOSTRING(E_Script, PuzzleBoardScript)
			ENUMTOSTRING(E_Script, PuzzleDotScript)
			ENUMTOSTRING(E_Script, PuzzleEntry)
			ENUMTOSTRING(E_Script, PuzzleExit)
			ENUMTOSTRING(E_Script, LineScript)
			ENUMTOSTRING(E_Script, PlayerScript)
			ENUMTOSTRING(E_Script, TextScript)
			ENUMTOSTRING(E_Script, UI_Hit)
			ENUMTOSTRING(E_Script, Life)
			ENUMTOSTRING(E_Script, Timer)
			ENUMTOSTRING(E_Script, FailureCheck)
			ENUMTOSTRING(E_Script, LevelUpdater)
	}
}

E_Script enumScr::conversion(const string& p_str)
{
	STRINGTOENUM(E_Script, TestScript)
	STRINGTOENUM(E_Script, TestScript2)
	STRINGTOENUM(E_Script, TestScript3)
	STRINGTOENUM(E_Script, GameStart)
	STRINGTOENUM(E_Script, GameExit)
	STRINGTOENUM(E_Script, MoveMap)
		STRINGTOENUM(E_Script, MoveMap2)
	STRINGTOENUM(E_Script, PuzzleBoardScript)
	STRINGTOENUM(E_Script, PuzzleDotScript)
	STRINGTOENUM(E_Script, PuzzleEntry)
	STRINGTOENUM(E_Script, PuzzleExit)
	STRINGTOENUM(E_Script, LineScript)
	STRINGTOENUM(E_Script, PlayerScript)
	STRINGTOENUM(E_Script, TextScript)
	STRINGTOENUM(E_Script, UI_Hit)
		STRINGTOENUM(E_Script, Life)
		STRINGTOENUM(E_Script, Timer)
		STRINGTOENUM(E_Script, FailureCheck)
		STRINGTOENUM(E_Script, LevelUpdater)
}