#include "KeyInputComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "KeyInputCommand.h"
#include "Script.h"
#include "E_Component.h"
#include "Rect.h"
#include "Vector2.h"
#include "Math.h"
#include "WindowMsg.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "GameData.h"

KeyInputComponenet::KeyInputComponenet()
{
}

KeyInputComponenet::~KeyInputComponenet()
{
}

bool KeyInputComponenet::isPressed()
{
	TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
	if (!tempcom2) return false;

	POINT tempPoint;

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));

		tempPoint.x = tempcom->getpivot().getx() + WINDOWX / 2;
		tempPoint.y = tempcom->getpivot().gety() + WINDOWY / 2;
		break;
	}

	/*
	if(temp.first == temp.second) return;
	GameObject* obj = temp.first.operator*().second;
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));

	return Math::isin(tempcom2->getrectptr(), tempcom->getpivot());*/
	return Math::isin(tempcom2->getrectptr(), Math::ScreentoCart(Vector2(tempPoint.x, tempPoint.y)));
}

bool KeyInputComponenet::isPressed2()
{
	TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
	if (!tempcom2) return false;

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);

	if(temp.first == temp.second) return false;
	GameObject* obj = temp.first.operator*().second;
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));

	return Math::isin(tempcom2->getrectptr(), tempcom->getpivot());
}

void KeyInputComponenet::OnPressed()
{
	if (KeyInputCommand* tempcommand = dynamic_cast<KeyInputCommand*>(owner->getscriptptr()))
	{
		tempcommand->play();
	}
}

