#pragma once

#include <list>
#include <map>
#include <vector>
#include <string>
#include "SingletonCls.h"

using namespace std;

class GameObject;
class Vector2;
enum class E_Objtype;
typedef multimap< E_Objtype, GameObject*>::iterator ObjIter;
class AllObject : public SingletonCls<AllObject>
{
private:
	multimap<E_Objtype, GameObject*> allObj;
	vector<ObjIter> safedelete;
	bool updated = false;
public:
	AllObject();
	virtual ~AllObject();
public:

	ObjIter allObjbegin();
	ObjIter allObjend();

	void ratedelelte();
	pair<ObjIter, ObjIter> getallObj(const E_Objtype&);
	void push(const E_Objtype& p_key, GameObject* p_obj);
	void clear();
	void setActiveGroup(const E_Objtype& p_key, bool p_bool);
	void setActiveGroup(const E_Objtype& first, const E_Objtype& second, bool p_bool);
	void addPivotGroup(const E_Objtype& p_key, const Vector2& p_vec);
	void deleteGroup(const E_Objtype& p_key);

	void deleteObj(ObjIter);
	void deleteObj(GameObject*);

	bool getupdated();
	void setupdated(bool);
};

