#pragma once
#include "Script.h"
#include "UpdateCommand.h"

using namespace std;
class GameObject;
class Vector2;
class LineScript : public Script, public UpdateCommand
{
private:
	GameObject* first;
	const GameObject* second;
	bool isend;
public:
	LineScript(GameObject*, const GameObject*);

public:
	virtual void Awake(GameObject* p_owner);
	virtual void play();
	void Setting();



	GameObject* getfirstptr();
	bool getisend();

	void setsecond(const GameObject*);
	void setisend(bool);
};

