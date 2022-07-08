#include "EventStruct2.h"
#include "Vector2.h"

template class EventStruct2<Vector2>;

template<typename T>
EventStruct2<T>::EventStruct2(Cls* p_Instance, void(Cls::* p_FNptr)(T)) : Instance(p_Instance), FNptr(p_FNptr)
{
}

template<typename T>
inline void EventStruct2<T>::play(T p_param)
{
	(Instance->*FNptr)(p_param);
}

template<typename T>
inline bool EventStruct2<T>::isSame(Cls* p_Instance, void(Cls::* p_FNptr)(T))
{
	return Instance == p_Instance ? FNptr == p_FNptr : false;
}
