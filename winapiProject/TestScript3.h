#pragma once

#include "Script.h"
#include "InputCommand.h"

class TestScript3 : public Script, public InputCommand
{
private:
	bool togle;
public:
	TestScript3();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
};

