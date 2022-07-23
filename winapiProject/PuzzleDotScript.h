#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleDotScript : public Script, public KeyInputFunction
{
private:
	int refCount;
	int number;
public:
	PuzzleDotScript();
	PuzzleDotScript(int);
	virtual ~PuzzleDotScript();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();

	void plusrefCount();
	void minusrefCount();


	int getnumber();
	void setnumber(int);
private:
	void clickLogic();
};