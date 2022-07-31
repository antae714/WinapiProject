#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "Vector2.h"


AllObject::AllObject()
{
}

AllObject::~AllObject()
{
    clear();
}

ObjIter AllObject::allObjbegin()
{
    return allObj.begin();
}

ObjIter AllObject::allObjend()
{
    return allObj.end();
}

pair<ObjIter, ObjIter> AllObject::getallObj(const E_Objtype& p_key)
{
    return allObj.equal_range(p_key);
}

void AllObject::push(const E_Objtype& p_key, GameObject* p_obj)
{
    allObj.emplace(p_key, p_obj);
}

void AllObject::clear()
{
    for (pair< E_Objtype, GameObject*> item : allObj) {
        delete item.second;
    }
    allObj.clear();
}

void AllObject::setActiveGroup(const E_Objtype& p_key, bool p_bool)
{
    pair<ObjIter, ObjIter> tempiter = allObj.equal_range(p_key);
    for (ObjIter iter = tempiter.first; iter != tempiter.second; ++iter) {
        iter.operator*().second->setisActive(p_bool);
    }
}

void AllObject::addPivotGroup(const E_Objtype& p_key, const Vector2& p_vec)
{
    pair<ObjIter, ObjIter> tempiter = allObj.equal_range(p_key);
    for (ObjIter iter = tempiter.first; iter != tempiter.second; ++iter) {
        dynamic_cast<TransformComponent*>(iter.operator*().second->getcomponent(E_Component::TransformComponent))->addpivot(p_vec);
    }
}

void AllObject::deleteGroup(const E_Objtype& p_key)
{
    pair<ObjIter, ObjIter> tempiter = allObj.equal_range(p_key);
    for (ObjIter iter = tempiter.first; iter != tempiter.second; ++iter) {
        delete iter.operator*().second;
    }
    allObj.erase(tempiter.first, tempiter.second);
    updated = true;
}

void AllObject::deleteObj(ObjIter iter)
{
    delete iter.operator*().second;
    allObj.erase(iter);
}

bool AllObject::getupdated() {
    return updated;
}

void AllObject::setupdated(bool p_updated) {
    updated = p_updated;
}