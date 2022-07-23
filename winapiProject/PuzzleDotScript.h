#pragma once

#include "Script.h"
#include "KeyInputFunction.h"

class PuzzleDotScript : public Script, public KeyInputFunction
{
private:
	int refCount;
	int number;
public:
	PuzzleDotScript();
	PuzzleDotScript(int);
	virtual ~PuzzleDotScript();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();

	void plusrefCount();
	void minusrefCount();


	int getnumber();
	void setnumber(int);
private:
	void clickLogic();
};