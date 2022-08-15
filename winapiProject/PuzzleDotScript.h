#pragma once
#include <vector>
#include "Script.h"
#include "KeyInputFunction.h"
using namespace std;

class GameObject;
class PuzzleDotScript : public Script, public KeyInputFunction
{
private:
	int refCount;
	int number;
	int status;
	vector<GameObject*> line;
public:
	PuzzleDotScript();
	PuzzleDotScript(int);
	virtual ~PuzzleDotScript();
public:
	//��ǲ �Ŵ������� �ҷ��ͼ� ȣ��
	virtual void KeyInput();

	void plusrefCount(GameObject*);
	void minusrefCount();
	void cut();

	int getrefCount();
	int getnumber();
	void setnumber(int);
private:
	void clickLogic();
	void CreateAbility();
};