#pragma once
#include "Script.h"

class PuzzleBoardScript : public Script
{
private:
	int answercheck;
public:
	PuzzleBoardScript();
public:
	bool isAnswer(const GameObject*, const GameObject*);

	void answer();
};