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
public:
	PuzzleEnemy1();
public:
	virtual void Start();
	virtual void Update();
	virtual void OnCollisonEnter(GameObject* other);
};

