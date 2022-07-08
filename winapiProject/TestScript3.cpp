#include "TestScript3.h"
#include "LevelData.h"

TestScript3::TestScript3()
{
	togle = false;
}

void TestScript3::play()
{
	if (togle) {
		togle = false;
		LevelData::DeletePuzzle1();
	}
	else {
		togle = true;
		LevelData::Puzzle1();
	}

}
