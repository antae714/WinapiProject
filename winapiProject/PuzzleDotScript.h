#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class PuzzleDotScript : public Script, public KeyInputCommand
{
private:
	int refCount;
public:
	PuzzleDotScript();
	virtual ~PuzzleDotScript();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();

	void plusrefCount();
	void minusrefCount();
private:
	void clickLogic();
};