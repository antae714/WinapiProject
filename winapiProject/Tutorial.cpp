#include "Tutorial.h"
#include "LevelData.h"
#include "LevelLoader.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "Vector2.h"
#include "GameData.h"
#include "Rect.h"
#include "Macro.h"

Tutorial::Tutorial()
{
	page = 0;
}

void Tutorial::KeyInput()
{
	AllObject* allObject = AllObject::getInstance();
	if (page == 0) {
		LevelData::LevelLode(E_Objtype::Tutorial);
	}
	if (page == 1) {
		GameObject* obj = (*allObject->getallObj(E_Objtype::Tutorial).first).second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("Tutorial2", 500, 500);
	}
	if (page == 2) {
		GameObject* obj = (*allObject->getallObj(E_Objtype::Tutorial).first).second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("Tutorial3", 500, 500);
	}
	if (page == 3) {
		GameObject* obj = (*allObject->getallObj(E_Objtype::Tutorial).first).second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("Tutorial4", 500, 500);
	}
	if (page == 4) {
		GameObject* obj = (*allObject->getallObj(E_Objtype::Tutorial).first).second;
		allObject->deleteGroup(E_Objtype::Tutorial);

		GameData* gamedata = GameData::getInstance();
		gamedata->setvarias("level1_3_npc", gamedata->getvarias("level1_3_npc") + 1);

		return;
	}
	++page;
}