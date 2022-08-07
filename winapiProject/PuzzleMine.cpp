#include "PuzzleMine.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameTime.h"
#include "Camera.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "CollisonCompoenet.h"
#include "LineScript.h"
#include "UI_Hit.h"
#include "Vector2.h"
#include "SoundManager.h"
#include "Math.h"
#include "Macro.h"

PuzzleMine::PuzzleMine(GameObject* p_master)
{
	master = p_master;
}

void PuzzleMine::Update()
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	TextureComponent* playertxt = nullptr;
	GameObject* obj = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
		playertxt = dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent));
		break;
	}

	TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));

	if (Math::isin(tempcom2->getrectptr(), playertxt->getrectptr())) {
		pair<ObjIter, ObjIter> temp2 = allObject->getallObj(E_Objtype::puzzleliner);
		for (ObjIter iter = temp2.first; iter != temp2.second; ++iter) {
			GameObject* obj = iter.operator*().second;
			LineScript* line = GETSCRIPT(obj, LineScript);
			if (!line->getisend()) {
				line->setisend(true);
				allObject->deleteObj(obj);
			}
		}
		master->setisActive(false);
		owner->setisActive(false);

		pair<ObjIter, ObjIter> temp3 = allObject->getallObj(E_Objtype::background);
		for (ObjIter iter = temp3.first; iter != temp3.second; ++iter) {
			GameObject* obj = iter.operator*().second;
			UI_Hit* hit = GETSCRIPT(obj, UI_Hit);
			if (!hit) continue;

			hit->Hit();
			break;
		}
	}
}