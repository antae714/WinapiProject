#pragma once
#include "Script.h"
#include "UpdateFunction.h"

using namespace std;

class PuzzleMine : public Script, public UpdateFunction
{
private:
	GameObject* master;
public:
	PuzzleMine(GameObject*);
public:
	virtual void Update();
};