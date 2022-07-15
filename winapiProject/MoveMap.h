#pragma once
#include "Script.h"
#include "KeyInputCommand.h"
#include <string>

class MoveMap : public Script, public KeyInputCommand
{
private:
	string m_src, m_dest;
	int m_pos_x, m_pos_y;

public:
	MoveMap();
	void Set(string, string, int, int);
public:
	virtual void play();
};