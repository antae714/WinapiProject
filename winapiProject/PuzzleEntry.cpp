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

PuzzleEntry::PuzzleEntry()
{
}

void PuzzleEntry::play()
{
	LevelData::LevelLode("PuzzleBoard");
	LevelData::LevelLode("puzzleDot");
	LevelData::LevelLode("puzzleHint");
	//TestScript2::AnswerFn();

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character2", 100, 150);

		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(Vector2(0, 0));

		PlayerScript* tempscr = dynamic_cast<PlayerScript*>(obj->getscriptptr());
		tempscr->SetMovableArea(300, -300, -300, 300);

		return;
	}
}
