#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleEntry : public Script, public KeyInputFunction
{
public:
	PuzzleEntry();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void KeyInput();
};

