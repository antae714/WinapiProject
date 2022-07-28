#pragma once

class GameObject;
class CollisonFunction
{
public:
	virtual void OnCollison(GameObject* other);
	virtual void OnCollisonEnter(GameObject* other);
	virtual void OnCollisonExit(GameObject* other);
};

