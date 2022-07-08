#pragma once

#include <list>
#include <map>
#include <vector>
#include <string>
#include "SingletonCls.h"

using namespace std;

class GameObject;
typedef list<GameObject*>::iterator ObjIter;
typedef multimap<string, ObjIter> ObjGroup;
class AllObject : public SingletonCls<AllObject>
{
private:
	list<GameObject*> objList;

	ObjGroup objGroup;
public:
	AllObject();
	virtual ~AllObject();
public:
	list<GameObject*>::iterator objListbegin();
	list<GameObject*>::iterator objListend();

	pair<ObjGroup::iterator, ObjGroup::iterator> getobjGroup(string);

	void push(GameObject*);
	void push(string p_group, GameObject* p_obj);
	void clear();

	void deleteGroup(string);
};

