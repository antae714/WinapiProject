#include "FailureCheck.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "PlayerScript.h"
#include "UITransformComponent.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "PuzzleExit.h"
#include "Timer.h"
#include "Rect.h"
#include "Math.h"
#include "Macro.h"

FailureCheck::FailureCheck()
{
}

void FailureCheck::Update()
{
	bool sw = false;
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	GameObject* obj = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
		if (dynamic_cast<PlayerScript*>(obj->getscriptptr())->getLife() <= 0) {
			sw = true;
		}
		break;
	}

	temp = allObject->getallObj(E_Objtype::PuzzleBoard_UI);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
		Timer* timer = dynamic_cast<Timer*>(obj->getscriptptr());

		if (timer) {
			if (timer->getTime() <= 0) {
				sw = true;
			}
			break;
		}
	}

	if (!sw) return;

	GameObject* gameObject = new GameObject();
	gameObject->pushcomponent(E_Component::UITransformComponent, new UITransformComponent(Vector2(640,360), 0));
	gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Red", Rect(200.f, 100.f), 200, 100));

	gameObject->Start();
	allObject->push(E_Objtype::PuzzleBoard_UI, gameObject);
}