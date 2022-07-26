#pragma once

#include <list>
#include <vector>
#include "Vector2.h"
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


template class EventList1<Vector2>;
template<typename T>
void EventList1<T>::hook(Cls* p_inst, void(Cls::* p_FNptr)(T))
{
	eventlist.push_back(EventStruct2<T>(p_inst, p_FNptr));
}

template<typename T>
void EventList1<T>::erase(Cls* p_inst, void(Cls::* p_FNptr)(T))
{
	/*vector<list<EventStruct2<T>>::iterator> eraseIterVec;
	for (list<EventStruct2<T>>::iterator iter = eventlist.begin(); iter != eventlist.end(); ++iter)
	{
		EventStruct2<T> tempStruct = *iter;
		if (tempStruct->isSame(p_cls, p_FNptr)) {
			eraseIterVec.push_back(iter);
		}
	}
	for (list<EventStruct2<T>>::iterator iter : eraseIterVec) {
		eventlist.erase(iter);
	}*/
}

template<typename T>
void EventList1<T>::play(T p_param)
{
	for (EventStruct2<T> item : eventlist) {
		item.play(p_param);
	}
}