#include "TestScript3.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "TestScript2.h"

TestScript3::TestScript3()
{
	togle = false;
}

void TestScript3::play()
{
	if (togle) {
		togle = false;
		LevelData::DeleteLevel("testPuzzel");
		LevelData::DeleteLevel(E_Objtype::puzzleliner);
		LevelData::DeleteLevel(E_Objtype::puzzlecleartest);

		AllObject* allObject = AllObject::getInstance();
		pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character", 100, 150);

			return;
		}

	}
	else {
		togle = true;
		LevelData::LevelLode("PuzzleBoard");
		LevelData::LevelLode("puzzleType");
		LevelData::LevelLode("puzzleDot");
		//TestScript2::AnswerFn();

		AllObject* allObject = AllObject::getInstance();
		pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("character2", 100, 150);

			TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
			tempcom->setpivot(Vector2(0, 0));
			return;
		}
	}

}
