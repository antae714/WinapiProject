#pragma once

#include <string>
#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleEntry : public Script, public KeyInputFunction
{
private:
	string str;
public:
	PuzzleEntry();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void KeyInput();
	virtual void Set(string);
};

