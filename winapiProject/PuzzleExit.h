#pragma once

#include "Script.h"
#include "InputFunction.h"

class PuzzleExit : public Script, public InputFunction
{
public:
	PuzzleExit();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void Input();
};

