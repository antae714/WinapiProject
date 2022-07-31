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
#include "CollisonCompoenet.h"
#include "Rect.h"
#include "Macro.h"

PuzzleEntry::PuzzleEntry()
{
}

void PuzzleEntry::KeyInput()
{
	//LevelData::DeleteLevel("testLevel");
	AllObject* allObject = AllObject::getInstance();
	allObject->setActiveGroup(E_Objtype::testLevel, false);
	allObject->setActiveGroup(E_Objtype::testLevel2, false);
	allObject->setActiveGroup(E_Objtype::text, false);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j) {

			GameObject* gameObject = new GameObject();
			gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(10 + (j - 4) * GRIDSIZE, -5 + (4 - i) * GRIDSIZE), 0));
			gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Starbutton", Rect(0.f, 50.f, 50.f), 50, 50));
			gameObject->pushcomponent(E_Component::KeyInputComponenet, new KeyInputComponenet());
			gameObject->setscript(new PuzzleDotScript(i * 9 + j));
			gameObject->Start();
			allObject->push(E_Objtype::puzzleDot, gameObject);
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j) {
			GameObject* gameObject = new GameObject();
			gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(10 + (j - 4.5f) * GRIDSIZE, -5 + (4.5f - i) * GRIDSIZE), 0));
			gameObject->pushcomponent(E_Component::CollisonCompoenet, new CollisonCompoenet(Rect(0, 70.f, 35.f)));
			gameObject->Start();
			allObject->push(E_Objtype::empty, gameObject);
		}
	}
	LevelData::LevelLode("PuzzleBoard");

	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	pair<ObjIter, ObjIter> temp2 = allObject->getallObj(E_Objtype::PuzzleBoard);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		TextureComponent* limittexture = GETCOMPONENT(temp2.first.operator*().second, TextureComponent);
		GameObject* obj = iter.operator*().second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character2", 100, 150);

		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(Vector2(0, 0));
		GameData* gameData = GameData::getInstance();
		gameData->setcameraPivot(tempcom->getpivotptr(), &limittexture->getrectptr());

		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(900, -900, -900, 900);
		tempscr->setmoveState(E_PlayerState::Puzzle);
		return;
	}
}
