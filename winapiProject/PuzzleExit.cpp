#include "PuzzleExit.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "Rect.h"
#include "TestScript2.h"
#include "PlayerScript.h"
#include "GameData.h"

PuzzleExit::PuzzleExit()
{
}

void PuzzleExit::Input()
{
	AllObject* allObject = AllObject::getInstance();
	//LevelData::LevelLode("testLevel");

	for (int i = (int)E_Objtype::level1_1; i <= (int)E_Objtype::level2_6; ++i) {
		allObject->setActiveGroup((E_Objtype)i, true);
	}
	allObject->setActiveGroup(E_Objtype::text, true);

	//버튼이 먼저 지워지면 에러
	LevelData::DeleteLevel(E_Objtype::puzzleliner);
	LevelData::DeleteLevel("puzzleHint");
	LevelData::DeleteLevel("PuzzleBoard");
	LevelData::DeleteLevel("PuzzleBoard_UI");
	LevelData::DeleteLevel("puzzleDot");
	LevelData::DeleteLevel("puzzleMine");
	LevelData::DeleteLevel("puzzleAbility");
	LevelData::DeleteLevel(E_Objtype::empty);
	LevelData::DeleteLevel(E_Objtype::puzzlecleartest);

	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character", 100, 150);
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setrect(Rect(0, 100, 150));

		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(Vector2(0, -200));
		GameData* gameData = GameData::getInstance();
		gameData->setcameraPivot(nullptr, nullptr);

		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(-150, -250, -590, 590);
		tempscr->setmoveState(E_PlayerState::Nomal);

		return;
	}
}
