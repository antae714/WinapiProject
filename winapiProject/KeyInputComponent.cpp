#include "KeyInputComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "KeyInputFunction.h"
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
		TextureComponent* tempcom = dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent));

		//tempPoint.x = tempcom->getpivot().getx() + WINDOWX / 2;
		//tempPoint.y = WINDOWY - (tempcom->getpivot().gety() + WINDOWY / 2);
		return Math::isin(tempcom2->getrectptr(), tempcom->getrectptr());
		break;
	}

	//return Math::isin(tempcom2->getrectptr(), Math::ScreentoCart(Vector2(tempPoint.x, tempPoint.y)));
}

void KeyInputComponenet::OnPressed()
{
	if (KeyInputFunction* tempcommand = dynamic_cast<KeyInputFunction*>(owner->getscriptptr()))
	{
		tempcommand->KeyInput();
	}
}


int KeyInputComponenet::getkey() {
	return interactive_key;
}


void KeyInputComponenet::setkey(int p_key) {
	interactive_key = p_key;
}

