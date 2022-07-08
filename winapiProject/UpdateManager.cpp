#include "UpdateManager.h"
#include "AllObject.h"
#include "GameObject.h"

void UpdateManager::Updating()
{
	AllObject* allObject = AllObject::getInstance();
	for (list<GameObject*>::iterator iter = allObject->objListbegin(); iter != allObject->objListend(); ++iter)
	{
		GameObject* obj = *iter;
		obj->Update();
	}
}
