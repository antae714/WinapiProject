#include "EventMap.h"
#include "EventStruct.h"

EventMap::EventMap()
{
}

EventMap::~EventMap()
{
	for (pair<Key, EventStruct*> item : eventmap) {
		delete item.second;
	}
	//eventmap.clear();
}

void EventMap::hook(Cls* p_inst, Key p_key, void(Cls::* p_FNptr)())
{
	eventmap.emplace(p_key, new EventStruct(p_inst, p_FNptr));
}

void EventMap::erase(Key p_key)
{
	if (ishavekey(p_key)) {
		delete eventmap.at(p_key);
		eventmap.erase(p_key);
	}
}

void EventMap::play(Key p_key)
{
	if (ishavekey(p_key)) {
		eventmap.at(p_key)->play();
	}
}

bool EventMap::ishavekey(Key p_key)
{
	map<Key, EventStruct*>::iterator iter = eventmap.find(p_key);
	return iter != eventmap.end();
}
