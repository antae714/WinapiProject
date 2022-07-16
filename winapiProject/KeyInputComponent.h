#pragma once
#include "Component.h"

class Rect;
class GameObject;
class KeyInputComponenet : public Component
{
public:
	KeyInputComponenet();
	virtual ~KeyInputComponenet();

public:
	bool isPressed();
	bool isPressed2();
	void OnPressed();
};

