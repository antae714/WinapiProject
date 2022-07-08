#include "TestScript2.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "AllObject.h"
#include "LevelLoader.h"
#include "E_Objtype.h"

TestScript2::TestScript2()
{
	isClicked = false;
}

void TestScript2::play()
{
	if (isClicked) {
		isClicked = false;
		dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent))->setbitmap("Starbutton", 20, 20);
	}
	else {
		isClicked = true;
		dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent))->setbitmap("Starbutton_Selected", 20, 20);
	}

	return;

	// 정답 판정이 필요할 경우
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::testPuzzel);

	int count = 0;
	bool stagesw[81] = { 0, };
	
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		TestScript2* temp = dynamic_cast<TestScript2*>(obj->getscriptptr());
		if (!temp) continue;

		if (temp->isClicked == true)
		{
			stagesw[count++] = true;
		}
		else
		{
			stagesw[count++] = false;
		}
	}
}
