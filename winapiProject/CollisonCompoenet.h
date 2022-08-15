#pragma once

#include "Component.h"
class Vector2;
class Rect;
class CollisonCompoenet : public Component
{
private:
	Rect* rect;
	bool istriger;
public:
	CollisonCompoenet();
	CollisonCompoenet(const Rect&);
	virtual ~CollisonCompoenet();
public:
	virtual void Start();

	GameObject* CollisonLogic();
	void OnCollison(CollisonCompoenet*);
	void OnCollisonEnter(CollisonCompoenet*);
	void OnCollisonExit(CollisonCompoenet*);


	const Rect& getrect();
	void setistriger(CollisonCompoenet* , bool);

	void setrect(const Rect&);
private:
	void transformset();
};