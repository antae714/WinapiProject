#include "EventList.h"
#include "EventStruct.h"
#include <vector>

EventList::EventList()
{
}

EventList::~EventList()
{
	for (EventStruct* item : eventlist) {
		delete item;
	}
	//eventlist.clear();
}

void EventList::hook(Cls* p_inst, void(Cls::* p_FNptr)())
{
	eventlist.push_back(new EventStruct(p_inst, p_FNptr));
}

void EventList::erase(Cls* p_cls, void(Cls::* p_FNptr)())
{
	vector<list<EventStruct*>::iterator> eraseIterVec;
	for (list<EventStruct*>::iterator iter = eventlist.begin(); iter != eventlist.end(); ++iter)
	{
		EventStruct* tempStruct = *iter;
		if (tempStruct->isSame(p_cls, p_FNptr)) {
			eraseIterVec.push_back(iter);
		}
	}
	for (list<EventStruct*>::iterator iter : eraseIterVec) {
		eventlist.erase(iter);
	}
}

void EventList::play()
{
	for (EventStruct* item : eventlist) {
		item->play();
	}
}
