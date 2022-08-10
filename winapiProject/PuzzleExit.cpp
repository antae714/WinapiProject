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

	//��ư�� ���� �������� ����
	LevelData::DeleteLevel(E_Objtype::puzzleliner);
	LevelData::DeleteLevel(E_Objtype::puzzleHint);
	LevelData::DeleteLevel(E_Objtype::PuzzleBoard);
	LevelData::DeleteLevel(E_Objtype::PuzzleBoard_UI);
	LevelData::DeleteLevel(E_Objtype::puzzleDot);
	LevelData::DeleteLevel(E_Objtype::puzzleMine);
	LevelData::DeleteLevel(E_Objtype::puzzleAbility);
	LevelData::DeleteLevel(E_Objtype::puzzleEnemy);
	LevelData::DeleteLevel(E_Objtype::empty);
	LevelData::DeleteLevel(E_Objtype::puzzlecleartest);

	GameObject* obj = (*allObject->getallObj(E_Objtype::character).first).second;

	dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character", 100, 150);
	dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setrect(Rect(100, 150));

	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
	tempcom->setpivot(Vector2(0, -200));
	GameData* gameData = GameData::getInstance();
	gameData->setcameraPivot(nullptr, nullptr);

	PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
	tempscr->SetMovableArea(-150, -250, -590, 590);
	tempscr->setmoveState(E_PlayerState::Nomal);

	return;
}
