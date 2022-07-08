#pragma once
#include "Component.h"

class Rect;
class GameObject;
class InputComponenet : public Component
{
public:
	InputComponenet();
	virtual ~InputComponenet();

public:
	bool isClicked();
	void Onclicked();
};

