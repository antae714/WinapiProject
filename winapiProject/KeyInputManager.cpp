#include "KeyInputManager.h"
#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "KeyInputComponent.h"
#include "WindowMsg.h"
#include "SoundManager.h"

#define VK_Z 0x5A
#define VK_X 0x58

void KeyInputManager::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	if (windowMsg->getiMessage() != WM_KEYDOWN) return;
	if (windowMsg->getwParam() != VK_Z &&
		windowMsg->getwParam() != VK_X) return;

	SoundManager::getInstance()->PlaySound_(E_Sound::Click);

	AllObject* allObject = AllObject::getInstance();
	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter)
	{
		GameObject* obj = iter.operator*().second;
		if (!obj->getisActive()) continue;
		KeyInputComponenet* tempcom2 = dynamic_cast<KeyInputComponenet*>(obj->getcomponent(E_Component::KeyInputComponenet));
		if (!tempcom2) continue;
		if (windowMsg->getwParam() != tempcom2->getkey()) continue;
		if (tempcom2->isPressed())
		{
			tempcom2->OnPressed();
			break;
		}
	}
	windowMsg->settingMsg(windowMsg->gethWnd(), 0, 0, 0);
}
