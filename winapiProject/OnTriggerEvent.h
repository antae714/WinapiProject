#pragma once

#include "SingletonCls.h"
#include "EventList.h"

class OnTriggerEvent : public EventList, public SingletonCls<OnTriggerEvent> {

};