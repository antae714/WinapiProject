#pragma once
#include "SingletonCls.h"

class PuzzleData : public SingletonCls<PuzzleData>
{
private:
	bool isclear;
public:
	PuzzleData();

public:
	bool getisclear();
	void setisclear(bool);

};

