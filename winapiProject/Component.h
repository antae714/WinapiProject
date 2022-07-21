#pragma once

#include <string>
#include <vector>

using namespace std;

class GameObject;
class Component
{
protected:
	GameObject* owner;
public:
	virtual ~Component();
public:
	virtual void Awake(GameObject* p_owner);
	virtual void Start();
};

