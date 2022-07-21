#include "Component.h"


Component::~Component()
{
}

void Component::Awake(GameObject* p_owner)
{
	owner = p_owner;
}

void Component::Start()
{
}
