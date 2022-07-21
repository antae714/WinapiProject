#include "PuzzleExit.h"
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

PuzzleExit::PuzzleExit()
{
}

void PuzzleExit::play()
{
	LevelData::DeleteLevel("PuzzleBoard");
	LevelData::DeleteLevel("puzzleDot");
	LevelData::DeleteLevel("puzzleHint");
	LevelData::DeleteLevel(E_Objtype::puzzlecleartest);
	LevelData::DeleteLevel(E_Objtype::puzzleliner);

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character", 100, 150);

		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(Vector2(350, -200));
		GameData* gameData = GameData::getInstance();
		gameData->setcameraPivot(nullptr);

		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(-150, -250, -590, 590);

		return;
	}
}
