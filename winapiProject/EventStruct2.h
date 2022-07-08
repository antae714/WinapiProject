#pragma once
#include "Cls.h"

template <typename T>
class EventStruct2
{
private:
	Cls* Instance;
	void(Cls::* FNptr)(T);

public:
	EventStruct2(Cls* p_Instance, void(Cls::* p_FNptr)(T));
public:
	void play(T p_param);

public:
	bool isSame(Cls* p_Instance, void(Cls::* p_FNptr)(T));
};
