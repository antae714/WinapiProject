#pragma once
#include "Script.h"
#include "UpdateFunction.h"

using namespace std;
class GameObject;
class Vector2;
class LineScript : public Script, public UpdateFunction
{
private:
	GameObject* first;
	const GameObject* second;
	bool isend;
public:
	LineScript();
	LineScript(GameObject*, const GameObject*);
	LineScript(GameObject*, const GameObject*, bool);
	virtual ~LineScript();
public:
	virtual void Set(int, int, bool);
	virtual void Awake(GameObject* p_owner);
	virtual void Start();
	virtual void play();
	void Setting();



	GameObject* getfirstptr();
	bool getisend();

	void setsecond(const GameObject*);
	void setisend(bool);
};