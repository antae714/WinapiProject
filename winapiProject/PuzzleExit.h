#pragma once

#include "Script.h"
#include "InputCommand.h"

class PuzzleExit : public Script, public InputCommand
{
public:
	PuzzleExit();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
};

