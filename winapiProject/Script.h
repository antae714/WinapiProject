#pragma once
class GameObject;
class Script
{
protected:
	GameObject* owner;
public:
	virtual ~Script();
public:
	virtual void Awake(GameObject* p_owner);
	virtual void Start();
	virtual void Set();
};

