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
	//인풋 매니저에서 불러와서 호출
	virtual void play();

	bool getisClicked() const;
	void setisClicked(bool);
private:
	void clickLogic();
};