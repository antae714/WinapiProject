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
	//인풋 매니저에서 불러와서 호출
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