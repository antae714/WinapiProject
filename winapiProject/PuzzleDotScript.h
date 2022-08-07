#pragma once
#include <vector>
#include "Script.h"
#include "KeyInputFunction.h"
using namespace std;
class LineScript;
class PuzzleDotScript : public Script, public KeyInputFunction
{
private:
	int refCount;
	int number;
	int status;
	vector<LineScript*> line;
public:
	PuzzleDotScript();
	PuzzleDotScript(int);
	virtual ~PuzzleDotScript();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void KeyInput();

	void plusrefCount(LineScript*);
	void minusrefCount();
	void cut();

	int getnumber();
	void setnumber(int);
private:
	void clickLogic();
	void CreateAbility();
};