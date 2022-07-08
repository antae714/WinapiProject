#include "Component.h"


void Component::Awake(GameObject* p_owner)
{
	owner = p_owner;
}

void Component::Start()
{
}
