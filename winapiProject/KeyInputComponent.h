#pragma once
#include "Component.h"

class Rect;
class GameObject;
class KeyInputComponenet : public Component
{
private:
	int interactive_key = 0x5A;
public:
	KeyInputComponenet();
	virtual ~KeyInputComponenet();

public:
	bool isPressed();
	void OnPressed();
	int getkey();
	void setkey(int);
};

