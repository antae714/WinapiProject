#pragma once

#include "Script.h"
#include "InputCommand.h"

class TestScript2 : public Script, public InputCommand
{
private:
	bool isClicked;
public:
	TestScript2();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
};

