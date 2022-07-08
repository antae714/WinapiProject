#pragma once
class GameObject;
class Script
{
protected:
	GameObject* owner;
public:
	virtual void Awake(GameObject* p_owner);
};

