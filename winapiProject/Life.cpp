#include "Life.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "PlayerScript.h"
#include "TextComponent.h"
#include "Vector2.h"
#include "SoundManager.h"
#include "Math.h"

Life::Life()
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	GameObject* obj = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
		life = dynamic_cast<PlayerScript*>(obj->getscriptptr())->getLife();
		break;
	}
}

void Life::Update()
{
	int currentlife;

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	GameObject* obj = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
		currentlife = dynamic_cast<PlayerScript*>(obj->getscriptptr())->getLife();
		break;
	}

	if (currentlife < life)
	{
		temp = allObject->getallObj(E_Objtype::Puzzleheart);
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			obj = iter.operator*().second;
			if (!obj->getisActive()) continue;

			obj->setisActive(false);

			if (--life == currentlife) {
				break;
			}
		}
	}
}