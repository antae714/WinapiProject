#include "LevelLoader.h"

// 스크립트
#include "TestScript.h"
#include "TestScript2.h"
#include "TestScript3.h"

Script* LevelLoader::AllocScript(const E_Script& p_enum)
{
	switch (p_enum)
	{
	case E_Script::TestScript:
		return new TestScript();
	case E_Script::TestScript2:
		return new TestScript2();
	case E_Script::TestScript3:
		return new TestScript3();

	default:
		return nullptr;
	}
}