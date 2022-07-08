#pragma once

#include "Cls.h"

class EventStruct
{
private:
	Cls* Instance;
	void(Cls::* FNptr)();

public:
	EventStruct(Cls* p_Instance, void(Cls::* p_FNptr)());
public:
	void play();

public:
	bool isSame(Cls* p_Instance, void(Cls::* p_FNptr)());
};