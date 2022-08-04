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

void AllObject::ratedelelte()
{
    for (ObjIter item : safedelete) {
        delete item.operator*().second;
        allObj.erase(item);
        safedelete.erase(safedelete.begin());
    }
}

pair<ObjIter, ObjIter> AllObject::getallObj(const E_Objtype& p_key)
{
    return allObj.equal_range(p_key);
}

void AllObject::push(const E_Objtype& p_key, GameObject* p_obj)
{
    p_obj->Start();
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

void AllObject::setActiveGroup(const E_Objtype& first, const E_Objtype& second, bool p_bool)
{
    for (int temp = (int)first; temp <= (int)second; ++temp) {
        pair<ObjIter, ObjIter> tempiter = allObj.equal_range((E_Objtype)temp);
        for (ObjIter iter = tempiter.first; iter != tempiter.second; ++iter) {
            iter.operator*().second->setisActive(p_bool);
        }
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
    safedelete.push_back(iter);
    /*delete iter.operator*().second;
    allObj.erase(iter);*/
}

void AllObject::deleteObj(GameObject* obj)
{
    for (ObjIter iter = allObj.begin(); iter != allObj.end();++iter) {
        if (iter.operator*().second == obj) {
            deleteObj(iter);
        }
    }
}

bool AllObject::getupdated() {
    return updated;
}

void AllObject::setupdated(bool p_updated) {
    updated = p_updated;
}