#include "InputManager.h"
#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "InputComponenet.h"
#include "WindowMsg.h"

void InputManager::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	if (windowMsg->getiMessage() != WM_LBUTTONDOWN) return;
	windowMsg->settingMsg(windowMsg->gethWnd(), 0, 0, 0);
	AllObject* allObject = AllObject::getInstance();
	for (list<GameObject*>::iterator iter = allObject->objListbegin(); iter != allObject->objListend(); ++iter)
	{
		GameObject* obj = *iter;
		InputComponenet* tempcom2 = dynamic_cast<InputComponenet*>(obj->getcomponent(E_Component::InputComponenet));
		if (!tempcom2) continue;
		if (tempcom2->isClicked()) {
			tempcom2->Onclicked();
			break;
		}
	}
}
