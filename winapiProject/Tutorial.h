#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class Tutorial : public Script, public KeyInputFunction
{
private:
	int page;
public:
	Tutorial();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void KeyInput();
};
