#include "PuzzleEntry.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "TestScript2.h"
#include "PlayerScript.h"
#include "GameData.h"
#include "PuzzleDotScript.h"
#include "KeyInputComponent.h"
#include "Rect.h"

PuzzleEntry::PuzzleEntry()
{
}

void PuzzleEntry::play()
{
	//testplay(); return;
	
	LevelData::LevelLode("PuzzleBoard");
	LevelData::LevelLode("puzzleDot");
	LevelData::LevelLode("puzzleHint");

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character2", 100, 150);

		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(Vector2(0, 0));
		GameData* gameData = GameData::getInstance();
		gameData->setcameraPivot(tempcom->getpivotptr());

		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(300, -300, -300, 300);

		return;
	}
}

void PuzzleEntry::testplay()
{
	//PuzzleBoardTest 를 PuzzleBoard로 변경후 사용
	LevelData::LevelLode("PuzzleBoard");
	AllObject* allObject = AllObject::getInstance();

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j) {

			GameObject* gameObject = new GameObject();
			gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2((i - 4) * GRIDSIZE, (j - 4) * GRIDSIZE), 0));
			gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Starbutton", Rect(0.f, 50.f, 50.f), 50, 50));
			gameObject->pushcomponent(E_Component::KeyInputComponenet, new KeyInputComponenet());
			gameObject->setscript(new PuzzleDotScript());
			gameObject->Start();
			allObject->push(E_Objtype::puzzleDot, gameObject);
		}

	}

	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character2", 100, 150);

		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(Vector2(0, 0));
		GameData* gameData = GameData::getInstance();
		gameData->setcameraPivot(tempcom->getpivotptr());

		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(900, -900, -900, 900);
		tempscr->setmoveState(E_PlayerState::Puzzle);
		return;
	}
}
