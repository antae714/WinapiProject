#include "PuzzleEntry.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "PlayerScript.h"
#include "GameData.h"
#include "PuzzleDotScript.h"
#include "KeyInputComponent.h"
#include "CollisonCompoenet.h"
#include "PuzzleBoardScript.h"
#include "Rect.h"
#include "Macro.h"
#include <time.h>

PuzzleEntry::PuzzleEntry()
{
}	

void PuzzleEntry::KeyInput()
{
	srand(time(NULL));
	AllObject* allObject = AllObject::getInstance();

	for (int i = (int)E_Objtype::level1_1; i <= (int)E_Objtype::level2_6; ++i) {
		allObject->setActiveGroup((E_Objtype)i, false);
	}
	allObject->setActiveGroup(E_Objtype::text, false);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j) {

			GameObject* gameObject = new GameObject();
			gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(10 + (j - 4) * GRIDSIZE, -5 + (4 - i) * GRIDSIZE), 0));
			gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Starbutton", Rect(50.f, 50.f)));
			gameObject->pushcomponent(E_Component::KeyInputComponenet, new KeyInputComponenet());
			gameObject->setscript(new PuzzleDotScript(i * 9 + j));
			allObject->push(E_Objtype::puzzleDot, gameObject);
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j) {
			GameObject* gameObject = new GameObject();
			gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(10 + (j - 4.5f) * GRIDSIZE, 40 + (4.5f - i) * GRIDSIZE), 0));
			gameObject->pushcomponent(E_Component::CollisonCompoenet, new CollisonCompoenet(Rect(50.f, 5.f)));
			allObject->push(E_Objtype::empty, gameObject);
		}
	}
	
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	GameObject* obj = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(900, -900, -900, 900);
		tempscr->setmoveState(E_PlayerState::Puzzle);
		tempscr->LifeReset();
		break;
	}
	//ÆÛÁñ»ý¼º
	//LevelData::LevelLode("PuzzleBoard");
	GameObject* Boardobj = new GameObject();
	{
		Boardobj->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(), 0));
		Boardobj->pushcomponent(E_Component::TextureComponent, new TextureComponent("backgroundpuzzle", Rect(2318.f, 2318.f)));
		PuzzleBoardScript* PuzzleBoard = new PuzzleBoardScript();
		PuzzleBoard->Set(str);
		Boardobj->setscript(PuzzleBoard);
		allObject->push(E_Objtype::PuzzleBoard, Boardobj);
	}

	LevelData::LevelLode("PuzzleBoard_UI");
	LevelData::LevelLode("Puzzleheart");

	TextureComponent* limittexture = GETCOMPONENT(Boardobj, TextureComponent);

	dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setrect(Rect(60, 90));

	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
	tempcom->setpivot(Vector2(0, 0));
	GameData* gameData = GameData::getInstance();
	gameData->setcameraPivot(tempcom->getpivotptr(), &limittexture->getrectptr());

	PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
	tempscr->SetMovableArea(900, -900, -900, 900);
	tempscr->setmoveState(E_PlayerState::Puzzle);
}

void PuzzleEntry::Set(string p_str)
{
	str = p_str;
}
