#include "AllObject.h"
#include "GameObject.h"


AllObject::AllObject()
{
}

AllObject::~AllObject()
{
    clear();
}

list<GameObject*>::iterator AllObject::objListbegin()
{
    return objList.begin();
}

list<GameObject*>::iterator AllObject::objListend()
{
    return objList.end();
}

pair<ObjGroup::iterator, ObjGroup::iterator> AllObject::getobjGroup(string p_str)
{
    return  objGroup.equal_range(p_str);
}

void AllObject::push(GameObject* p_obj)
{
    objList.push_back(p_obj);
}
void AllObject::push(string p_group, GameObject* p_obj) 
{
    objList.push_back(p_obj);
    objGroup.emplace(p_group, --objList.end());
}

void AllObject::clear()
{
    for (GameObject* item : objList) {
        delete item;
    }
    objList.clear();
}

void AllObject::deleteGroup(string p_str)
{
    pair<ObjGroup::iterator, ObjGroup::iterator> tempiter = objGroup.equal_range(p_str);
    for (ObjGroup::iterator iter = tempiter.first; iter != tempiter.second; ++iter) {
        delete *iter.operator*().second;
        objList.erase(iter.operator*().second);
    }
    objGroup.erase(tempiter.first, tempiter.second);
}
