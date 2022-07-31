#include "UpdateManager.h"
#include "AllObject.h"
#include "GameObject.h"

void UpdateManager::Updating()
{
	AllObject* allObject = AllObject::getInstance();
	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter)
	{
		GameObject* obj = iter.operator*().second;
		if (!obj->getisActive()) continue;
		obj->Update();


		if (allObject->getupdated()) {
			allObject->setupdated(false);
			break;
		}
	}
}
