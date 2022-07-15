#include "KeyInputManager.h"
#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "KeyInputComponent.h"
#include "WindowMsg.h"

#define VK_Z 0x5A

void KeyInputManager::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	if (windowMsg->getiMessage() != WM_KEYDOWN || windowMsg->getwParam() != VK_Z) return;
	windowMsg->settingMsg(windowMsg->gethWnd(), 0, 0, 0);
	AllObject* allObject = AllObject::getInstance();
	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter)
	{
		GameObject* obj = iter.operator*().second;
		KeyInputComponenet* tempcom2 = dynamic_cast<KeyInputComponenet*>(obj->getcomponent(E_Component::KeyInputComponenet));
		if (!tempcom2) continue;
		if (tempcom2->isPressed())
		{
			tempcom2->OnPressed();
			break;
		}
	}
}
