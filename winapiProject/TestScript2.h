#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class TestScript2 : public Script, public KeyInputFunction
{
private:
	bool isClicked;
	static void AddLine(Vector2, Vector2);

public:
	TestScript2();
public:
	//인풋 매니저에서 불러와서 호출
	virtual void play();
	void Activate();
	static void AnswerFn();
};

