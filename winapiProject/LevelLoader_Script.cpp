#include "LevelLoader.h"

// 스크립트
#include "GameStart.h"
#include "GameExit.h"
#include "MoveMap.h"
#include "PuzzleBoardScript.h"
#include "PuzzleDotScript.h"
#include "PuzzleEntry.h"
#include "PuzzleExit.h"
#include "LineScript.h"
#include "PlayerScript.h"
#include "TextScript.h"
#include "UI_Hit.h"
#include "Life.h"
#include "Timer.h"
#include "FailureCheck.h"

Script* LevelLoader::AllocScript(const E_Script& p_enum)
{
	switch (p_enum)
	{
	case E_Script::GameStart:
		return new GameStart();
	case E_Script::GameExit:
		return new GameExit();
	case E_Script::MoveMap:
		return new MoveMap();
	case E_Script::PuzzleBoardScript:
		return new PuzzleBoardScript();
	case E_Script::PuzzleDotScript:
		return new PuzzleDotScript();
	case E_Script::PuzzleEntry:
		return new PuzzleEntry();
	case E_Script::PuzzleExit:
		return new PuzzleExit();
	case E_Script::LineScript:
		return new LineScript(); 
	case E_Script::PlayerScript:
		return new PlayerScript();
	case E_Script::TextScript:
		return new TextScript();
	case E_Script::UI_Hit:
		return new UI_Hit();
	case E_Script::Life:
		return new Life();
	case E_Script::Timer:
		return new Timer();
	case E_Script::FailureCheck:
		return new FailureCheck();

	default:
		_ASSERT(0 && "존재하지않는 스크립트");
		return nullptr;
	}
}