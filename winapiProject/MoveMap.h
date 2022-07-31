#pragma once
#include "Script.h"
#include "UpdateFunction.h"
#include <string>

using namespace std;

class MoveMap : public Script, public UpdateFunction
{
private:
	string m_src, m_dest;
	int m_pos_x, m_pos_y;

public:
	MoveMap();
	virtual void Set(string, string, int, int);
public:
	virtual void play();
};