#pragma once
#include "Script.h"
#include "KeyInputFunction.h"
#include <string>

using namespace std;

class MoveMap2 : public Script, public KeyInputFunction
{
private:
	string m_src, m_dest;
	int m_pos_x, m_pos_y;

public:
	MoveMap2();
	virtual void Set(string, string, int, int);
public:
	virtual void KeyInput();
};