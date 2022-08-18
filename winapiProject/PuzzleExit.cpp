#include "PuzzleExit.h"
#include "SoundManager.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "Rect.h"
#include "PlayerScript.h"
#include "AnimationStruct.h"
#include "PuzzleData.h"
#include "GameData.h"
#include "CollisonCompoenet.h"
#include "Macro.h"
#include "GameData.h"

PuzzleExit::PuzzleExit()
{
}

void PuzzleExit::Input()
{
	AllObject* allObject = AllObject::getInstance();
	SoundManager::getInstance()->changeBackground(E_Sound::BackGround);
	SoundManager::getInstance()->setBGSMute(true);
	//LevelData::LevelLode("testLevel");

	for (int i = (int)E_Objtype::level1_1; i <= (int)E_Objtype::level2_6; ++i) {
		allObject->setActiveGroup((E_Objtype)i, true);
	}
	allObject->setActiveGroup(E_Objtype::text, true);

	//버튼이 먼저 지워지면 에러
	LevelData::DeleteLevel(E_Objtype::puzzleliner);
	LevelData::DeleteLevel(E_Objtype::puzzleHint);
	LevelData::DeleteLevel(E_Objtype::PuzzleBoard);
	LevelData::DeleteLevel(E_Objtype::PuzzleBoard_UI);
	LevelData::DeleteLevel(E_Objtype::Puzzleheart);
	LevelData::DeleteLevel(E_Objtype::puzzleDot);
	LevelData::DeleteLevel(E_Objtype::puzzleMine);
	LevelData::DeleteLevel(E_Objtype::puzzleAbility);
	LevelData::DeleteLevel(E_Objtype::puzzleEnemy);
	LevelData::DeleteLevel(E_Objtype::empty);
	LevelData::DeleteLevel(E_Objtype::puzzlecleartest);

	GameObject* player = (*allObject->getallObj(E_Objtype::character).first).second;
	CollisonCompoenet* coll = GETCOMPONENT(player, CollisonCompoenet);
	coll->setrect(Rect(100, 150));
	TextureComponent* texture = dynamic_cast<TextureComponent*>(player->getcomponent(E_Component::TextureComponent));

	texture->setrect(Rect(100, 150));

	//texture->getanimationptr()->setisupdate(true);
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(player->getcomponent(E_Component::TransformComponent));
	tempcom->setpivot(Vector2(0, -200));
	GameData* gameData = GameData::getInstance();
	gameData->setcameraPivot(nullptr, nullptr);

	PlayerScript* tempscr = dynamic_cast<PlayerScript*>(player->getscriptptr());
	tempscr->SetMovableArea(-150, -250, -590, 590);
	tempscr->setmoveState(E_PlayerState::Nomal);
	tempscr->setismove(true);

	PuzzleData::deleteInstance();

	return;
}
