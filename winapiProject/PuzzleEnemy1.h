#pragma once

#include "Script.h"
#include "UpdateFunction.h"
#include "CollisonFunction.h"

class TransformComponent;
class PuzzleEnemy1 : public Script, public UpdateFunction , public CollisonFunction
{
private:
	TransformComponent* transform;
	TransformComponent* transform2;
	int speed;
public:
	PuzzleEnemy1();
public:
	virtual void Start();
	virtual void Set(int p_speed);
	virtual void Update();
	virtual void OnCollisonEnter(GameObject* other);

private:
	void pivotset();
};

