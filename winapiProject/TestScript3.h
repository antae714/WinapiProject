#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class TestScript3 : public Script, public KeyInputCommand
{
private:
	bool togle;
public:
	TestScript3();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
};

