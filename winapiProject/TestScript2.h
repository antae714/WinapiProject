#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class TestScript2 : public Script, public KeyInputCommand
{
private:
	bool isClicked;
	static void AddLine(Vector2, Vector2);

public:
	TestScript2();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
	void Activate();
	static void AnswerFn();
};

