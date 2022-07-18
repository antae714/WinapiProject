#pragma once

#include "Script.h"
#include "KeyInputCommand.h"

class PuzzleDotScript : public Script, public KeyInputCommand
{
private:
	bool isClicked;

public:
	PuzzleDotScript();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void play();

	bool getisClicked() const;
	void setisClicked(bool);
private:
	void clickLogic();
};