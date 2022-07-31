#include "GameObject.h"
#include "Component.h"
#include "E_Component.h"
#include "Script.h"
#include "UpdateFunction.h"

GameObject::GameObject()
{
	isActive = true;
	script = nullptr;
}

GameObject::~GameObject()
{
	if (script) {
		delete script;
		script = nullptr;
	}
	for (pair<E_Component, Component*> item : componentMap) {
		delete item.second;
	}
}

void GameObject::Start()
{
	for (pair<E_Component, Component*> item : componentMap) {
		item.second->Start();
	}
	if (script) {
		script->Start();
	}
}

void GameObject::Update()
{
	for (pair<E_Component, Component*> item : componentMap) {
		if (dynamic_cast<UpdateFunction*>(item.second)) {
			dynamic_cast<UpdateFunction*>(item.second)->Update();
		}
	}
	if (dynamic_cast<UpdateFunction*>(script))
		dynamic_cast<UpdateFunction*>(script)->Update();
}

void GameObject::pushcomponent(E_Component p_key, Component* p_com)
{
	componentMap.emplace(p_key, p_com);
	p_com->Awake(this);
}

Component* GameObject::getcomponent(E_Component p_key) const
{
	map<E_Component, Component*>::const_iterator iter = componentMap.find(p_key);
	if (end(componentMap) == iter) {
		return nullptr;
	}
	return iter.operator*().second;
}

bool GameObject::getisActive() const
{
	return isActive;
}

void GameObject::setisActive(bool p_bool)
{
	if (!isActive && p_bool) {
		isActive = p_bool;
		for(pair<E_Component, Component*> item : componentMap) {
			item.second->Start();
		}
	}
	else {
		isActive = p_bool;
	}
}

Script* GameObject::getscriptptr() const
{
	return script;
}

void GameObject::setscript(Script* p_script)
{
	script = p_script;
	script->Awake(this);
}
