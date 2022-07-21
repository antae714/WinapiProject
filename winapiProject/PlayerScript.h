#pragma once
#include <map>
#include <array>

#include "Script.h"
#include "UpdateCommand.h"

using namespace std;
#define PLAYERSPEED 2
#define GRIDSIZE 210

enum class E_PlayerState {
	Nomal,
	Puzzle,

	MAX
};
class PlayerScript : public Script, public UpdateCommand
{
private:
	map<int, void(PlayerScript::*)()> Fnptrplay;
	E_PlayerState moveState;
	int x;
	int y;
	int speed;

	int top;
	int bottom;
	int left;
	int right;
public:
	PlayerScript();
public:
	virtual void play();
	void SetMovableArea();
	void SetMovableArea(int, int, int, int);
	void setmoveState(E_PlayerState);

private:
	void InputLogic();
	void MoveLogic();

	void NomalMove();
	void PuzzleMove();
	void xplus();
	void xminus();
	void yplus();
	void yminus();

};