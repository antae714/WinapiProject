#include "CollisonLogic.h"
#include "AllObject.h"
#include "Macro.h"
#include "CollisonCompoenet.h"
#include "E_Component.h"
#include "GameObject.h"

void CollisonLogic::Update()
{
	return;
	AllObject* allObject = AllObject::getInstance();
	vector<ObjIter> itervec;
	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter)
	{
		GameObject* obj = iter.operator*().second;
		if(GETCOMPONENT(obj, CollisonCompoenet))
			itervec.push_back(iter);
	}
	if (itervec.empty()) return;
	for (int i = itervec.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < itervec.size() - 1; ++j)
		{
			CollisonCompoenet* first = GETCOMPONENT(itervec.at(i).operator*().second, CollisonCompoenet);
			CollisonCompoenet* second = GETCOMPONENT(itervec.at(j).operator*().second, CollisonCompoenet);
			/*if (first->CollisonLogic(second)) {
				first->OnCollisonEnter(second);
				second->OnCollisonEnter(first);
			}*/
		}
		itervec.erase(--itervec.end());
	}
}
