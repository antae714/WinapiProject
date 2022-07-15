#include "E_Script.h"

string enumScr::conversion(const E_Script& p_enum)
{
	switch (p_enum)
	{
	case E_Script::TestScript:
		return "TestScript";
	case E_Script::TestScript2:
		return "TestScript2";
	case E_Script::TestScript3:
		return "TestScript3";
	case E_Script::GameStart:
		return "GameStart";
	case E_Script::GameExit:
		return "GameExit";
	case E_Script::MoveMap:
		return "MoveMap";
	}
}

E_Script enumScr::conversion(const string& p_str)
{
	if ("TestScript" == p_str)
		return E_Script::TestScript;
	else if ("TestScript2" == p_str)
		return E_Script::TestScript2;
	else if ("TestScript3" == p_str)
		return E_Script::TestScript3;
	else if ("GameStart" == p_str)
		return E_Script::GameStart;
	else if ("GameExit" == p_str)
		return E_Script::GameExit;
	else if ("MoveMap" == p_str)
		return E_Script::MoveMap;
}