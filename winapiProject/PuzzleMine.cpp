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
#include "PlayerScript.h"
#include "Vector2.h"
#include "SoundManager.h"
#include "Math.h"
#include "Macro.h"
#include "PuzzleData.h"

PuzzleMine::PuzzleMine(GameObject* p_master)
{
	master = p_master;
}

void PuzzleMine::Update()
{
	if (PuzzleData::getInstance()->getisclear()) return;

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	GameObject* player = player = temp.first.operator*().second;;
	TextureComponent* playertxt = dynamic_cast<TextureComponent*>(player->getcomponent(E_Component::TextureComponent));
	

	TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));

	if (Math::isin(tempcom2->getrectptr(), playertxt->getrectptr())) {

		dynamic_cast<PlayerScript*>(player->getscriptptr())->onHit();

		master->setisActive(false);
		owner->setisActive(false);
	}
}
