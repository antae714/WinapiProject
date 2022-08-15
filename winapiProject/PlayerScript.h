#pragma once
#include <map>
#include <array>

#include "Script.h"
#include "UpdateFunction.h"

using namespace std;
#define PLAYERSPEED 2
#define GRIDSIZE 205

enum class E_PlayerState {
	Nomal,
	Puzzle,

	MAX
};
class PlayerScript : public Script, public UpdateFunction
{
private:
	E_PlayerState moveState;
	int x;
	int y;
	int speed;

	int top;
	int bottom;
	int left;
	int right;

	double cooldown;
	bool cooldown_sw;
	bool first_sw;

	int life;

	bool is_moving, prev_is_moving;
	bool is_dashing, prev_is_dashing;
	int direction, prev_direction;
	double animation_time;
	int animation_phase;

	bool ismove;
public:
	PlayerScript();
public:
	virtual void Update();
	void SetMovableArea();
	void SetMovableArea(int, int, int, int);
	void setmoveState(E_PlayerState);
	void Ability();
	void onHit();
	void Damage();
	void LifeReset();
	int getLife();
	void AnimationUpdate();

	bool getismove();
	void setismove(bool);

private:
	void InputLogic();
	void MoveLogic();
	void AbilityUpdate();

	void LimitArea();
};