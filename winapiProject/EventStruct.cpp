#include "EventStruct.h"

EventStruct::EventStruct(Cls* p_Instance, void(Cls::* p_FNptr)()) : Instance(p_Instance), FNptr(p_FNptr) {

}

void EventStruct::play()
{
	(Instance->*FNptr)();
}

bool EventStruct::isSame(Cls* p_Instance, void(Cls::* p_FNptr)())
{
	return Instance == p_Instance ? FNptr == p_FNptr : false;
}
