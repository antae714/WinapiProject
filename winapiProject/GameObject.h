#pragma once

#include <map>

using namespace std;
enum class E_Component;
class Component;
class Script;
class GameObject
{
private:
	bool isActive;
	map<E_Component, Component*> componentMap;
	Script* script;

public:
	GameObject();
	virtual ~GameObject();

public:
	void Start();
	void Update();

	void pushcomponent(E_Component, Component*);
	void deletecomponent(E_Component);

	Component* getcomponent(E_Component) const;

	bool getisActive() const;
	void setisActive(bool);

	Script* getscriptptr() const;
	void setscript(Script*);

	void deletescript();
};


