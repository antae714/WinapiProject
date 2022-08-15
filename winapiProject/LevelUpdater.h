#pragma once
#include "Script.h"
#include "UpdateFunction.h"

class LevelUpdater : public Script, public UpdateFunction
{
private:
	int level;
public:
	LevelUpdater();
public:
	virtual void Update();
	virtual void Set(int);

	void level1_1();
	void level1_2();
	void level1_3();
	void level1_4();
	void level1_5();
	void level1_6();
	void level2_1();
	void level2_2();
	void level2_3();
	void level2_4();
	void level2_5();
	void level2_6();
};

