#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class PuzzleEntry : public Script, public KeyInputCommand
{
public:
	PuzzleEntry();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();
	void testplay();
};

