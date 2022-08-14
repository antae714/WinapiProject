#pragma once
#include "Script.h"
#include "UpdateFunction.h"

enum class E_enemyState {
	search,
	move,
	attack,

	MAX
};

class GameObject;
class Vector2;
class TransformComponent;
class PuzzleEnemy2 : public Script, public UpdateFunction
{
private:
	E_enemyState state;
	GameObject* target;
	TransformComponent* transform;
	TransformComponent* transform2;
	int speed;
	double attacktime;
public:
	PuzzleEnemy2();

public:
	virtual void Update();
	virtual void Set(int p_speed);
	void Init();


private:
	void movestate();
	void attacktate();
	void pivotset();
	void search();
};
