#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class TestScript3 : public Script, public KeyInputFunction
{
private:
	bool togle;
public:
	TestScript3();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
};

