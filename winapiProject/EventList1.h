#pragma once

#include <list>
#include "EventStruct2.h"
using namespace std;
class Cls;

template <typename T>
class EventList1
{
private:
	list<EventStruct2<T>> eventlist;
public:
	void hook(Cls* p_inst, void(Cls::* p_FNptr)(T));
	void erase(Cls* p_inst, void(Cls::* p_FNptr)(T));
	void play(T p_param);
};