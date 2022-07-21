#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class PuzzleDotScript : public Script, public KeyInputCommand
{
private:
	int refCount;
public:
	PuzzleDotScript();
	virtual ~PuzzleDotScript();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();

	void plusrefCount();
	void minusrefCount();
private:
	void clickLogic();
};