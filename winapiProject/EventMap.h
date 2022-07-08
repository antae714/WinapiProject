#pragma once

#include <map>

using namespace std;

typedef int Key;

class Cls;
class EventStruct;
class EventMap {
private:
	map<Key, EventStruct*> eventmap;

public:
	EventMap();
	virtual ~EventMap();

public:
	void hook(Cls* p_inst, Key p_key, void(Cls::* p_FNptr)());
	void erase(Key p_key);
	void play(Key p_key);

protected:
	//Ű�� �̹��Ҵ�Ǿ��ִٸ� ��
	bool ishavekey(Key p_key);
};