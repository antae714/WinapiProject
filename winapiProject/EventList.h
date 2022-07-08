#pragma once
#include <list>
using namespace std;
class Cls;
class EventStruct;

class EventList
{
private:
	list<EventStruct*> eventlist;

public:
	EventList();
	virtual ~EventList();

public:
	void hook(Cls* p_inst, void(Cls::* p_FNptr)());
	void erase(Cls* p_inst, void(Cls::* p_FNptr)());
	void play();
};