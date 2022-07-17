#include "InputManager.h"
#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "InputComponenet.h"
#include "WindowMsg.h"
#include "SoundManager.h"

void InputManager::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	if (windowMsg->getiMessage() != WM_LBUTTONDOWN) return;
	SoundManager::getInstance()->PlaySound_(E_Sound::Click);
	windowMsg->settingMsg(windowMsg->gethWnd(), 0, 0, 0);
	AllObject* allObject = AllObject::getInstance();
	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter)
	{
		GameObject* obj = iter.operator*().second;
		InputComponenet* tempcom2 = dynamic_cast<InputComponenet*>(obj->getcomponent(E_Component::InputComponenet));
		if (!tempcom2) continue;
		if (tempcom2->isClicked()) {
			tempcom2->Onclicked();
			break;
		}
	}
}
